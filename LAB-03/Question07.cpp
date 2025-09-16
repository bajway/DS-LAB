/*Create a circular link list and perform the mentioned tasks.
a. Insert a new node at the end of the list.
b. Insert a new node at the beginning of list.
c. Insert a new node at given position.
d. Delete any node.
e. Print the complete circular link list.*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() : head(nullptr) {}
//a)
    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

//b)
    void insertBegin(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

//c)
    void insertAtPos(int val, int pos)
    {
        if (pos == 1)
        {
            insertBegin(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

//d. Delete node by value
    void deleteNode(int val)
    {
        if (head==nullptr)
            return head;

        Node *curr = head;
        Node *prev = nullptr;

        // Case 1: deleting head
        if (head->data == val)
        {
            if (head->next == head)
            { // only one node
                delete head;
                head = nullptr;
                return;
            }
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = head->next;
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }

        //Case 2: deleting non-head
        do
        {
            prev = curr;
            curr = curr->next;
            if (curr->data == val)
           {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
    }

//e)
    void printList()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
