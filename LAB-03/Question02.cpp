/*Write a program that prompts the user to enter a number indicating how many elements to move to the
end of a linked list. The program should then move that exact number of elements from the beginning of
the linked list to the end.
Example: given list: 5, 3 1 8 6 4 2
Enter the number: 2
After rotation: 1 8 6 4 2 5 3*/

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
Node *moveNElements(Node *head, int pos)
{
    if (head == nullptr || pos == 0)
        return head;
    Node *temp = head; // main head pointer copy
    int count = 1;
    while (count < pos && temp->next != nullptr)
    {
        temp = temp->next;
        count++;
    }
    if (!temp->next)
        return head;
    Node *newHead = temp->next; // new head

    temp->next = nullptr; // break list
    Node *temp2 = newHead;
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = head;
    return newHead;
}

int main()
{
    vector<int> arr = {5, 3, 1, 8, 6, 4, 2};
    Node *head = convertArr2LL(arr);
    printLL(head);
    head = moveNElements(head, 2);
    printLL(head);
    return 0;
}