#include <iostream>
using namespace std;

// 🔹 Node structure (basic unit)
struct Node {
    int data;      // value
    Node* next;    // next node ka address

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

//////////////////////////////////////////////////////////////
// 🔹 INSERTION (for building the list)
//////////////////////////////////////////////////////////////

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    // agar list empty hai
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    // last node tak jao
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

//////////////////////////////////////////////////////////////
// 🔹 TRAVERSAL
//////////////////////////////////////////////////////////////

void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

//////////////////////////////////////////////////////////////
// 🔹 UTILITIES (MAIN TOPIC)
//////////////////////////////////////////////////////////////

// 🔸 Count total nodes
int countNodes(Node* head) {
    int count = 0;

    Node* temp = head;

    // traversal karke count increase karo
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}


// 🔸 Search (check if value exists)
bool contains(Node* head, int value) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == value) {
            return true;  // mil gaya
        }
        temp = temp->next;
    }

    return false; // nahi mila
}


// 🔸 Sum of all values
int sumAll(Node* head) {
    int sum = 0;

    Node* temp = head;

    while (temp != nullptr) {
        sum += temp->data; // add current value
        temp = temp->next;
    }

    return sum;
}


// 🔸 Reverse linked list (IMPORTANT 🔥)
void reverseList(Node*& head) {

    Node* prev = nullptr;   // previous node
    Node* curr = head;      // current node
    Node* next = nullptr;   // next node

    // jab tak list khatam nahi hoti
    while (curr != nullptr) {

        next = curr->next;   // next node store karo

        curr->next = prev;   // link reverse karo

        prev = curr;         // prev aage badhao
        curr = next;         // curr aage badhao
    }

    // final me head ko last node pe set karo
    head = prev;
}


// 🔸 Destroy entire list (memory free)
void destroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//////////////////////////////////////////////////////////////
// 🔹 MAIN FUNCTION (YOUR ORIGINAL FLOW)
//////////////////////////////////////////////////////////////

int main() {

    // 🔹 Build: 1 -> 2 -> 3
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);

    printList(head);


    // 🔹 Count nodes
    // expected: 3
    cout << "countNodes: " << countNodes(head) << "\n";


    // 🔹 Search value 2
    // expected: yes
    cout << "contains 2? "
         << (contains(head, 2) ? "yes" : "no") << "\n";


    // 🔹 Sum of all values
    // expected: 1+2+3 = 6
    cout << "sumAll: " << sumAll(head) << "\n";


    // 🔹 Reverse list
    // before: 1 -> 2 -> 3
    // after : 3 -> 2 -> 1
    reverseList(head);

    cout << "reversed: ";
    printList(head);


    // 🔹 Cleanup memory
    destroyList(head);

    return 0;
}