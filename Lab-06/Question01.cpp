/*Suppose you are building a program to manage a to-do list for a busy professional. You decide
to use a stack to keep track of the items on the list. Write a code snippet that demonstrates how you
would add a new item to the top of the stack, check if the stack is empty, and remove the top item
from the stack.*/

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

class Stack{
    Node *top;
    int st_size;

public:
    Stack(){
        top = NULL;
        st_size = 0;
    }
    
    void addItem(string item){
        Node *newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        st_size += 1;
        cout << "item " << newNode->val << " added in stack!" << endl;
    }
    void isEmpty(){
        if(top==NULL)
            cout << "Stack is Empty" << endl;
        else
            cout << "Stack not empty, items in stack: " << st_size << endl;
    }

    void removeItem(){
        if(top==NULL)
            cout << "Stack underFlow" << endl;
        Node *temp = top;
        top = top->next;
        cout << "Item " << temp->val << " Removed!" << endl;
        delete temp;
        st_size -= 1;
        
    }
};
int main(){
    Stack st;
    st.addItem("Cake");
    st.addItem("Strawberry");
    st.addItem("Apple Juice");
    st.isEmpty();
    st.removeItem();
    st.isEmpty();
    return 0;
}