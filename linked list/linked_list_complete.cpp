#include <iostream>
using namespace std;

// 🔹 Node structure (Linked List ka base unit)
struct Node {
    int data;        // value store karega
    Node* next;      // next node ka address

    // constructor (node create karte time call hota hai)
    Node(int value) {
        data = value;
        next = nullptr;  // initially next null hota hai
    }
};

//////////////////////////////////////////////////////////////
// 🔹 INSERTION FUNCTIONS
//////////////////////////////////////////////////////////////

// Beginning me insert
void insertAtBeginning(Node*& head, int value) {

    Node* newNode = new Node(value);  // new node create

    // new node ka next current head ko point karega
    newNode->next = head;

    // head update (new node first ban gaya)
    head = newNode;
}


// End me insert
void insertAtEnd(Node*& head, int value) {

    Node* newNode = new Node(value);

    // agar list empty hai
    if (head == nullptr) {
        head = newNode;   // direct head ban jayega
        return;
    }

    Node* temp = head;

    // last node tak traverse karo
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // last ke baad new node attach karo
    temp->next = newNode;
}


// Position pe insert (1-based index)
void insertAtPosition(Node*& head, int value, int pos) {

    // invalid position check
    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    // position 1 means beginning
    if (pos == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    // (pos-1)th node tak jao
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // agar position list ke bahar hai
    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }

    Node* newNode = new Node(value);

    // 🔥 pointer linking (MOST IMPORTANT)
    newNode->next = temp->next;  // new node → next
    temp->next = newNode;        // previous node → new node
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

// total nodes count
int countNodes(Node* head) {
    int count = 0;

    while (head != nullptr) {
        count++;
        head = head->next;
    }

    return count;
}


// value search
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


// 🔥 reverse linked list (very important)
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

    // final head update
    head = prev;
}

//////////////////////////////////////////////////////////////
// 🔹 DELETION
//////////////////////////////////////////////////////////////

// beginning se delete
void deleteFromBeginning(Node*& head) {

    if (head == nullptr) return;

    Node* temp = head;       // current head store
    head = head->next;       // head shift

    delete temp;             // old node free
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

    delete temp->next;   // last node delete
    temp->next = nullptr;
}


// value se delete
void deleteByValue(Node*& head, int value) {

    if (head == nullptr) return;

    // first node match kare
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

    temp->next = toDelete->next;  // bypass

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
// 🔹 DESTROY LIST (full cleanup)
//////////////////////////////////////////////////////////////

void destroyList(Node*& head) {

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//////////////////////////////////////////////////////////////
// 🔹 MAIN FUNCTION (FULL DEMO)
//////////////////////////////////////////////////////////////

int main() {

    // 🔹 Step 1: Empty list
    Node* head = nullptr;

    // 🔹 Step 2: Insert operations
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtBeginning(head, 5);

    // list: 5 -> 10 -> 20
    cout << "After inserts: ";
    printList(head);


    // 🔹 Step 3: Insert in middle
    insertAtPosition(head, 15, 3);

    // list: 5 -> 10 -> 15 -> 20
    cout << "Insert 15 at pos 3: ";
    printList(head);


    // 🔹 Step 4: Utilities
    cout << "Count: " << countNodes(head) << "\n";
    cout << "Contains 20? " << (contains(head, 20) ? "yes" : "no") << "\n";
    cout << "Sum of all values: " << sumAll(head) << "\n";


    // 🔹 Step 5: Deletion
    deleteByValue(head, 10);
    cout << "After delete 10: ";
    printList(head);

    deleteAtPosition(head, 2);
    cout << "After delete position 2: ";
    printList(head);

    deleteFromEnd(head);
    cout << "After delete end: ";
    printList(head);


    // 🔹 Step 6: Reverse
    reverseList(head);
    cout << "Reversed: ";
    printList(head);


    // 🔹 Step 7: Cleanup
    destroyList(head);
    cout << "Cleared. head is nullptr: "
         << (head == nullptr ? "yes" : "no") << "\n";

    return 0;
}