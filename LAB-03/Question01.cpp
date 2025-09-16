/*You are given the array (3 1 2, 5, 8) of size 5 print that array on screen. Then create singly linked list from
that array , Now add the 9 at the end , 11 pos 3, and 4 at the front and list. Now delete the 1, 2, and 5 then
print the linked list.*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
// singly LL
Node *convertArr2LL(int arr[], int size)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *addAtEnd(Node *head, int el)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(el);
    temp->next = newNode;
    return head;
}
Node *addAtPos(Node *head, int pos, int el)
{
    Node *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == pos - 1)
        {
            Node *tempNode = new Node(el);
            tempNode->next = temp->next;
            temp->next = tempNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
Node *addAtFront(Node *head, int el)
{
    Node *tempNOde = new Node(el, head);
    return tempNOde;
}
Node *deleteAtPos(Node *head, int pos)
{

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == pos)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    int size = 5;
    int arr[size] = {3, 1, 2, 5, 8};
    Node *head = convertArr2LL(arr, size);
    printLL(head);
    head = addAtEnd(head, 9);
    printLL(head);
    head = addAtPos(head, 3, 11);
    printLL(head);
    head = addAtFront(head, 4);
    printLL(head);

    // delete at position
    head = deleteAtPos(head, 5);
    printLL(head);
    head = deleteAtPos(head, 1);
    printLL(head);
    head = deleteAtPos(head, 2);
    printLL(head);
    return 0;
}