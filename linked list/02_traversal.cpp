#include "node.hpp"
#include "traversal.hpp"

int main() {

    // 🔹 Step 1: Linked list create karna
    // head first node ka address store karega
    Node* head = new Node(5);

    // second node create karke link kar diya
    head->next = new Node(7);

    // third node create karke link kar diya
    head->next->next = new Node(2);

    // last node ka next always nullptr hota hai
    head->next->next->next = nullptr;


    // 🔹 Step 2: Traversal function call
    // printList function internally traversal karega
    std::cout << "List: ";
    printList(head);


    // 🔹 Step 3: Memory cleanup (VERY IMPORTANT )

    // sabse last node delete karo
    delete head->next->next;

    // second node delete karo
    delete head->next;

    // first node delete karo
    delete head;

    // dangling pointer avoid karne ke liye
    head = nullptr;


    return 0;
}