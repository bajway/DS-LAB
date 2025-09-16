/*Solve the following problem using a Singly Linked List.Given a Linked List of integers or string,
write a function to check if the entirety of the linked list is a palindrome or not
*/
// EXAMPLE INPUT---> Consider a LL
bool isPalindrome(Node *head)
{
    if (!head || !head->next)
        return true;

    // find a middle
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reversing second half
    Node *prev = nullptr;
    Node *curr = slow->next;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // checking by comparison
    Node *first = head;
    Node *second = prev;
    while (second)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
} // function to check palindrome
