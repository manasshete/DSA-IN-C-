#include <iostream>
using namespace std;

// 🔹 Node structure (basic unit of linked list)
struct Node {
    int data;      // value store karta hai
    Node* next;    // next node ka address

    Node(int value) {
        data = value;
        next = nullptr;  // default: end
    }
};

//////////////////////////////////////////////////////////////
// 🔹 INSERTION FUNCTIONS (needed to build initial list)
//////////////////////////////////////////////////////////////

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);

    newNode->next = head; // new node points to current head
    head = newNode;       // head update
}

// Insert at end
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

    temp->next = newNode; // attach at end
}

// Insert at position (1-based)
void insertAtPosition(Node*& head, int value, int pos) {
    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    // pos-1 tak jao
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    Node* newNode = new Node(value);

    // 🔥 pointer linking
    newNode->next = temp->next;
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
// 🔹 DELETION FUNCTIONS (MAIN TOPIC)
//////////////////////////////////////////////////////////////

// 🔸 Delete from beginning
void deleteFromBeginning(Node*& head) {

    // agar list empty hai
    if (head == nullptr) {
        return;
    }

    Node* temp = head;     // current head store
    head = head->next;     // head ko next pe shift karo

    delete temp;           // old node free
}


// 🔸 Delete from end
void deleteFromEnd(Node*& head) {

    // empty list
    if (head == nullptr) return;

    // sirf ek node hai
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // second last node tak jao
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // last node delete karo
    delete temp->next;

    // last ka next null karo
    temp->next = nullptr;
}


// 🔸 Delete by value (first occurrence)
void deleteByValue(Node*& head, int value) {

    // empty list
    if (head == nullptr) return;

    // agar first node hi delete karna hai
    if (head->data == value) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    // value dhundho (previous node tak)
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    // agar value mila hi nahi
    if (temp->next == nullptr) {
        cout << "Value not found\n";
        return;
    }

    // delete target node
    Node* toDelete = temp->next;

    // link bypass
    temp->next = toDelete->next;

    delete toDelete;
}


// 🔸 Delete by position (1-based)
void deleteAtPosition(Node*& head, int pos) {

    if (pos <= 0 || head == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    // first node delete
    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    // pos-1 tak jao
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    // agar position out of range
    if (temp->next == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    Node* toDelete = temp->next;

    // bypass
    temp->next = toDelete->next;

    delete toDelete;
}

//////////////////////////////////////////////////////////////
// 🔹 DESTROY LIST (FULL CLEANUP)
//////////////////////////////////////////////////////////////

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

    Node* head = nullptr;

    // 🔹 Build list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 15, 3);

    // List: 5 -> 10 -> 15 -> 20
    cout << "Start: ";
    printList(head);


    // 🔹 Delete by value (10)
    // Result: 5 -> 15 -> 20
    deleteByValue(head, 10);
    cout << "After delete value 10: ";
    printList(head);


    // 🔹 Delete at position 2
    // Result: 5 -> 20
    deleteAtPosition(head, 2);
    cout << "After delete position 2: ";
    printList(head);


    // 🔹 Delete from end
    // Result: 5
    deleteFromEnd(head);
    cout << "After delete end: ";
    printList(head);


    // 🔹 Delete from beginning
    // Result: empty
    deleteFromBeginning(head);
    cout << "After delete beginning: ";
    printList(head);


    // 🔹 Cleanup (safe even if empty)
    destroyList(head);

    return 0;
}