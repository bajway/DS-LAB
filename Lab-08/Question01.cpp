/*Implement a binary search tree and perform all operations you learned above like:
Inserting, Deleting, Searching, and Traversing.*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node *insertNode(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insertNode(root->left, val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int val)
{
    if (!root)
        return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        else if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

bool searchNode(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return searchNode(root->left, val);
    return searchNode(root->right, val);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    int choice, val;
    while (true)
    {
        cout << "\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            root = insertNode(root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (searchNode(root, val) ? "Found\n" : "Not Found\n");
            break;
        case 4:
            inorder(root);
            cout << endl;
            break;
        case 5:
            preorder(root);
            cout << endl;
            break;
        case 6:
            postorder(root);
            cout << endl;
            break;
        case 7:
            return 0;
        }
    }
}
