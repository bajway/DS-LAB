/*Solve the following problem using a Singly Linked List.
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear
before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.*/
#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
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
Node *rearrangeLL(Node *head)
{
    Node *evenHead = nullptr, *evenTail = nullptr;
    Node *oddHead = nullptr, *oddTail = nullptr;

    Node *curr = head;

    while (curr != nullptr)
    {
        if (curr->data % 2 == 0)
        { // even condition

            if (evenHead == nullptr)
            {
                evenHead = curr;
                evenTail = curr;
            }
            else
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        }
        else
        {
            // odd condition
            if (oddHead == nullptr)
            {
                oddHead = curr;
                oddTail = curr;
            }
            else
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }
    if (evenHead == nullptr)
        return oddHead; // no even elemets in the list
    if (oddHead == nullptr)
        return evenHead; // no odd elements in thhe list

    evenTail->next = oddHead;
    oddTail->next = nullptr;

    return evenHead;
}

int main()
{
    vector<int> arr = {8, 12, 10, 4};
    Node *head = convertArr2LL(arr);
    head = rearrangeLL(head);
    printLL(head);
    arr = {1, 2, 4, 7, 5, 8, 10, 12, 13};
    head = convertArr2LL(arr);
    head = rearrangeLL(head);
    printLL(head);
}