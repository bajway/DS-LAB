#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int k) { key = k; height = 1; left = NULL; right = NULL; }
};

int heightNode(Node* n) {
    if(n == NULL) return 0;
    return n->height;
}

void updateHeight(Node* n) {
    n->height = 1 + max(heightNode(n->left), heightNode(n->right));
}

int getBalance(Node* n) {
    if(n == NULL) return 0;
    return heightNode(n->left) - heightNode(n->right);
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

Node* insertNode(Node* root, int key) {
    if(root == NULL) return new Node(key);

    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root;

    updateHeight(root);

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->key)
        return rightRotate(root);

    if(balance < -1 && key > root->right->key)
        return leftRotate(root);

    if(balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void levelOrder(Node* root) {
    if(root == NULL) return;
    Node* q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    while(front < rear) {
        Node* n = q[front++];
        cout << n->key << " ";
        if(n->left) q[rear++] = n->left;
        if(n->right) q[rear++] = n->right;
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    root = insertNode(root, 15);

    int height = heightNode(root);
    cout << height << endl;

    root = leftRotate(root);

    levelOrder(root);

    return 0;
}
