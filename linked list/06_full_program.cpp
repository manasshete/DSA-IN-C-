#include <iostream>
using namespace std;

// 🔹 Node structure (Linked List ka building block)
struct Node {
    int data;        // value store karega
    Node* next;      // next node ka address

    // constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

//////////////////////////////////////////////////////////////
// 🔹 INSERTION
//////////////////////////////////////////////////////////////

// Beginning me insert
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);

    // new node current head ko point karega
    newNode->next = head;

    // head update
    head = newNode;
}

// End me insert
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

    // last ke baad new node attach karo
    temp->next = newNode;
}

// Position pe insert (1-based index)
void insertAtPosition(Node*& head, int value, int pos) {

    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    // position 1 → beginning
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    // (pos-1)th node tak jao
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    Node* newNode = new Node(value);

    // 🔥 pointer linking (important)
    newNode->next = temp->next;
    temp->next = newNode;
}

//////////////////////////////////////////////////////////////
// 🔹 TRAVERSAL
//////////////////////////////////////////////////////////////

void printList(Node* head) {
    Node* temp = head;

    // jab tak list khatam nahi hoti
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "nullptr\n";
}

//////////////////////////////////////////////////////////////
// 🔹 UTILITIES
//////////////////////////////////////////////////////////////

// count nodes
int countNodes(Node* head) {
    int count = 0;

    while (head != nullptr) {
        count++;
        head = head->next;
    }

    return count;
}

// search value
bool contains(Node* head, int value) {
    while (head != nullptr) {
        if (head->data == value)
            return true;

        head = head->next;
    }
    return false;
}

// sum of all values
int sumAll(Node* head) {
    int sum = 0;

    while (head != nullptr) {
        sum += head->data;
        head = head->next;
    }

    return sum;
}

// 🔥 reverse list (important)
void reverseList(Node*& head) {

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {

        next = curr->next;   // next node store karo

        curr->next = prev;   // link reverse karo

        prev = curr;         // prev aage badhao
        curr = next;         // curr aage badhao
    }

    // final head update
    head = prev;
}

//////////////////////////////////////////////////////////////
// 🔹 DELETION
//////////////////////////////////////////////////////////////

// beginning se delete
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    delete temp;
}

// end se delete
void deleteFromEnd(Node*& head) {

    if (head == nullptr) return;

    // single node case
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

    delete temp->next;
    temp->next = nullptr;
}

// value se delete
void deleteByValue(Node*& head, int value) {

    if (head == nullptr) return;

    // agar first node hi match kare
    if (head->data == value) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    // previous node tak jao
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found\n";
        return;
    }

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}

// position se delete
void deleteAtPosition(Node*& head, int pos) {

    if (pos <= 0 || head == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    Node* toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}

//////////////////////////////////////////////////////////////
// 🔹 DESTROY LIST
//////////////////////////////////////////////////////////////

void destroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//////////////////////////////////////////////////////////////
// 🔹 MAIN FUNCTION
//////////////////////////////////////////////////////////////

int main() {

    Node* head = nullptr;

    // 🔹 Insert operations
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);

    // 5 -> 10 -> 20
    cout << "After inserts: ";
    printList(head);

    // insert at position
    insertAtPosition(head, 15, 3);

    // 5 -> 10 -> 15 -> 20
    cout << "Insert 15 at pos 3: ";
    printList(head);

    // utilities
    cout << "Count: " << countNodes(head) << "\n";
    cout << "Contains 20? " << (contains(head, 20) ? "yes" : "no") << "\n";
    cout << "Sum: " << sumAll(head) << "\n";

    // deletion
    deleteByValue(head, 10);
    cout << "After delete 10: ";
    printList(head);

    deleteAtPosition(head, 2);
    cout << "After delete position 2: ";
    printList(head);

    deleteFromEnd(head);
    cout << "After delete end: ";
    printList(head);

    // reverse
    reverseList(head);
    cout << "Reversed: ";
    printList(head);

    // cleanup
    destroyList(head);
    cout << "Cleared: " << (head == nullptr ? "yes" : "no") << "\n";

    return 0;
}