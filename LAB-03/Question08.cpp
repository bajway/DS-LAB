/*Task#8:
Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail preserved
nodes, into a single list that contains all the nodes of L followed by all the nodes of M.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
struct DoublyLinkedList {
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    //Append node at end
    void appendDLL(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printDLL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

DoublyLinkedList concatenate(DoublyLinkedList& L, DoublyLinkedList& M) {
    // If L is empty
    if (L.head == NULL) return M;

    // If M is empty
    if (M.head == NULL) return L;

    L.tail->next = M.head;
    M.head->prev = L.tail;

    L.tail = M.tail;
    return L;
}



int main() {
    DoublyLinkedList L, M;

    // First list L
    L.appendDLL(1);
    L.appendDLL(2);
    L.appendDLL(3);

    // Second list M
    M.appendDLL(4);
    M.appendDLL(5);
    M.appendDLL(6);

    cout << "List L: ";
    L.printDLL();
    cout << "List M: ";
    M.printDLL();

    // Concatenate L and M
    DoublyLinkedList combined = concatenate(L, M);

    cout << "Concatenated List: ";
    combined.printDLL();

    return 0;
}
