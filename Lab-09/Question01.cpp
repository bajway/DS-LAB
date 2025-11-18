#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) { key = k; left = NULL; right = NULL; height = 1; }
};

int heightNode(Node* n) {
    if(n == NULL) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if(n == NULL) return 0;
    return heightNode(n->left) - heightNode(n->right);
}

void updateHeight(Node* n) {
    n->height = 1 + max(heightNode(n->left), heightNode(n->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balance(Node* n) {
    updateHeight(n);
    int b = getBalance(n);
    if(b > 1 && getBalance(n->left) >= 0) return rightRotate(n);
    if(b > 1 && getBalance(n->left) < 0) { n->left = leftRotate(n->left); return rightRotate(n); }
    if(b < -1 && getBalance(n->right) <= 0) return leftRotate(n);
    if(b < -1 && getBalance(n->right) > 0) { n->right = rightRotate(n->right); return leftRotate(n); }
    return n;
}

Node* convertBST(Node* root) {
    if(root == NULL) return NULL;
    root->left = convertBST(root->left);
    root->right = convertBST(root->right);
    return balance(root);
}

int main() {
    Node* A = new Node(10);
    A->left = new Node(6);
    A->left->left = new Node(4);
    A->left->right = new Node(8);

    Node* B = new Node(10);
    B->right = new Node(16);
    B->right->left = new Node(12);
    B->right->right = new Node(18);

    A = convertBST(A);
    B = convertBST(B);

    return 0;
}

