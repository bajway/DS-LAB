/*Consider a library where books are borrowed and returned by multiple patrons. The library
has a limited number of staff members to handle the book transactions. As patrons arrive with books
to borrow or return, they are added to a linear queue. Each book transaction can take a variable amount
of time to complete, depending on factors such as the number of books being borrowed or returned,
and the availability of the staff members. Once a book transaction is completed, the next patron in the
queue is serviced.
Write a C++ program that simulates this library scenario using a linear queue data structure. The
program should allow patrons to add themselves to the queue, remove themselves from the queue
when their book transaction is completed, and display the current queue of patrons waiting for book
transactions to be serviced.*/

#include<iostream>
#include<string>
using namespace std;

struct Node{
    string val;
    Node *next;

    Node(string val){
        this->val = val;
        next = NULL;
    }
    Node(string val, Node* next){
        this->val = val;
        this->next = next;
    }
};

class Queue{
    Node *start, *end;
    int size;
    public:
    Queue(){
        start = end = NULL;
        size = 0;
    }

    void addPatron(string name){
        Node *newPatron = new Node(name);
        if(start==NULL){
            newPatron->next = start = end;
            start = end = newPatron;
        }
        end->next = newPatron;
        end = newPatron;
        cout << "Patron " << newPatron->val << " added" << endl;
    }

    void removePatron(){
        if(start==end)
            cout << "No Patron in Queue" << endl;
        Node *temp = start;
        start = start->next;
        cout << "Patron " << temp->val << " Transaction is completed, removed from queue " << endl;
        delete temp;
    }

    void showPatrons(){
        if(start==NULL){
            cout << "No Patrons in Queue" << endl;
        }
        Node *temp = start;
        while(temp!=NULL){
            cout << temp->val;
            if (temp->next != NULL)
                cout << "-->";
            temp=temp->next;
        }
    }
};

int main(){
    Queue q;
    q.addPatron("Kashif");
    q.addPatron("Baqar");
    q.addPatron("Omer");
    q.addPatron("Anwer");
    q.addPatron("Aasma");
    q.removePatron();
    q.removePatron();
    q.showPatrons();
    return 0;
}
