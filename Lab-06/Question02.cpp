/*Suppose you are implementing a program to keep track of a user's web browsing history using
a linked list and a stack. Whenever the user visits a new website, the website URL is added to the front
of the linked list to represent the most recent page visited. Additionally, the website URL is pushed
onto a stack to allow for the user to easily navigate back to the previous page.
Now suppose the user has visited 5 websites in the following order: Google, Facebook, Twitter,
LinkedIn, and Instagram. The user decides to click the "back" button twice to return to the Facebook
page. Write a function to implement this behavior using the linked list and stack.
Hint: You will need to pop two elements from the stack and remove the first two nodes from the
linked list.*/

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
    
    void addPage(string item){
        Node *newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        st_size += 1;
        cout << "Now at " << newNode->val<< endl;
    }
    void removePage(){
        if(top==NULL)
            cout << "Stack underFlow" << endl;
        Node *temp = top;
        top = top->next;
        if(top!=NULL)
            cout << "Now at " << top->val << endl;
        else
            cout << "No more history left!" << endl;
        delete temp;
        st_size -= 1;
        
    }
};
int main(){
    Stack st;
    st.addPage("Google");
    st.addPage("FaceBook");
    st.addPage("Twitter");
    st.addPage("LinkdIn");
    st.addPage("Instagram");
    cout << endl;
    cout << "Going Back-----" << endl;
    cout << endl;
    st.removePage();
    st.removePage();
    st.removePage();
  

    return 0;
}
