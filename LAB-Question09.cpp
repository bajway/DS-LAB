/*Given a linked list, you have to perform the following task:
1. Extract the alternative nodes starting from second node.
2. Reverse the extracted list.
3. Append the extracted list at the end of the original list.
Note: Try to solve the problem without using any extra memory.*/

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val, Node* next){
        data = val;
        this->next = next;
    }
    Node( int val)
    {
        data = val;
        next = NULL;
    }

};

Node* reverseAppendLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = even;

    while(even!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    Node *prev = NULL;
    Node *curr = evenhead;
    Node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    odd->next = prev;
    return head;
}

Node* insertAtEnd(Node* head, int val){
    Node *newNode = new Node(val);
    if(head==NULL)
        return newNode;
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;

    }
    temp->next = newNode;
    return head;
}
void printLL(Node* head){
    Node *temp = head;
    while(temp->next!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

int main(){
    Node *head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 60);
    head = insertAtEnd(head, 70);
    head = insertAtEnd(head, 80);
    head = insertAtEnd(head, 90);
    printLL(head);
    head = reverseAppendLL(head);
    printLL(head);
}
