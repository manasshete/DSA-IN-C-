#include <iostream>
using namespace std;

// 🔹 Node structure (Linked List ka basic building block)
struct Node {
    int data;     // value store karega
    Node* next;   // next node ka address store karega

    // constructor (node create karte time call hota hai)
    Node(int value) {
        data = value;
        next = nullptr;  // initially next null hota hai
    }
};


// 🔹 Insert at Beginning
void insertAtBeginning(Node*& head, int value) {

    // new node create karo
    Node* newNode = new Node(value);

    // new node ka next current head ko point karega
    newNode->next = head;

    // ab head ko new node pe shift karo
    head = newNode;
}


// 🔹 Insert at End
void insertAtEnd(Node*& head, int value) {

    // new node create karo
    Node* newNode = new Node(value);

    // agar list empty hai
    if (head == nullptr) {
        head = newNode;  // directly head ban jayega
        return;
    }

    // traversal ke liye temp pointer
    Node* temp = head;

    // last node tak jao (jiska next null ho)
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // last node ke next me new node attach karo
    temp->next = newNode;
}


// 🔹 Insert at Position (1-based index)
void insertAtPosition(Node*& head, int value, int pos) {

    // invalid position check
    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    // agar position 1 hai → beginning insertion
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    // traversal ke liye temp pointer
    Node* temp = head;

    // (pos-1)th node tak move karo
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // agar position list se bahar hai
    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    // new node create karo
    Node* newNode = new Node(value);

    // 🔥 IMPORTANT POINTER LINKING
    // step 1: new node ka next → temp ke next ko point kare
    newNode->next = temp->next;

    // step 2: temp ka next → new node ko point kare
    temp->next = newNode;
}


// 🔹 Print List (Traversal)
void printList(Node* head) {

    // temp pointer traversal ke liye
    Node* temp = head;

    // jab tak null nahi hota
    while (temp != nullptr) {

        // current node ka data print karo
        cout << temp->data << " -> ";

        // next node pe move karo
        temp = temp->next;
    }

    // end of list
    cout << "nullptr\n";
}


// 🔹 Delete Entire List (Memory cleanup)
void destroyList(Node*& head) {

    // jab tak list empty nahi hoti
    while (head != nullptr) {

        // current node store karo
        Node* temp = head;

        // head ko next pe move karo
        head = head->next;

        // old node delete karo
        delete temp;
    }
}


// 🔹 Main Function
int main() {

    // empty list create
    Node* head = nullptr;

    // Insert 10 at end → 10
    insertAtEnd(head, 10);

    // Insert 20 at end → 10 -> 20
    insertAtEnd(head, 20);

    // Insert 5 at beginning → 5 -> 10 -> 20
    insertAtBeginning(head, 5);

    cout << "After begin/end inserts: ";
    printList(head);


    // Insert 15 at position 3
    // before: 5 -> 10 -> 20
    // after : 5 -> 10 -> 15 -> 20
    insertAtPosition(head, 15, 3);

    cout << "After insert 15 at position 3: ";
    printList(head);


    // memory free karna (VERY IMPORTANT)
    destroyList(head);

    return 0;
}