#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (!node) return 0;
    return node->height;
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

int getBalance(Node* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key) {
    if (!node) return createNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root, int arr[], int &index) {
    if (!root) return;
    inorder(root->left, arr, index);
    arr[index++] = root->key;
    inorder(root->right, arr, index);
}

int kthSmallest(Node* root, int k) {
    int arr[100]; // max size
    int index = 0;
    inorder(root, arr, index);
    return arr[k-1];
}

int kthLargest(Node* root, int k) {
    int arr[100]; 
    int index = 0;
    inorder(root, arr, index);
    return arr[index - k];
}

int main() {
    Node* root = nullptr;
    int values[] = {10, 5, 15, 3, 7, 12};
    int n = 6;
    for(int i=0; i<n; i++)
        root = insert(root, values[i]);

    int k = 3;
    cout << "Kth smallest: " << kthSmallest(root, k) << endl;
    cout << "Kth largest: " << kthLargest(root, k) << endl;
    cout << "Left height from root: " << height(root->left) << endl;
    cout << "Right height from root: " << height(root->right) << endl;

    return 0;
}
