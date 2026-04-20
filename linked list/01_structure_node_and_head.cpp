#include "node.hpp"
#include <iostream>

int main() {

    // head pointer first node ka address store karega
    // agar list empty hai toh head = nullptr
    Node* head = nullptr;

    std::cout << "Empty list: head is nullptr? "
              << (head == nullptr ? "yes" : "no") << "\n";


    // 🔹 Step 1: First node create karna (heap memory me)
    // new Node(1) ek node banata hai jisme data = 1
    head = new Node(1);


    // 🔹 Step 2: Second node create karna aur link karna
    // head->next matlab first node ka next pointer
    head->next = new Node(2);


    // 🔹 Step 3: Second node ko last mark karna
    // last node ka next always nullptr hota hai
    head->next->next = nullptr;


    // 🔹 Step 4: Traversal (list print karna)
    std::cout << "Manual list: ";

    // ek temporary pointer banaya traversal ke liye
    Node* t = head;

    // jab tak pointer nullptr nahi ho jata
    while (t != nullptr) {

        // current node ka data print karo
        std::cout << t->data << " -> ";

        // next node pe move karo
        t = t->next;
    }

    // last me nullptr print karo (end of list)
    std::cout << "nullptr\n";


    // 🔹 Step 5: Memory cleanup (VERY IMPORTANT )
    
    // pehle second node delete karo
    delete head->next;

    // fir first node delete karo
    delete head;

    // good practice: dangling pointer avoid karne ke liye
    head = nullptr;


    return 0;
}