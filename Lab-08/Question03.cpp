/*Create the BST which stores the students object in BST and student object has the
property like name, roll and score. Create tree based on name of student AND Perform
following operations in BST:
 Insert the student record,
 Search the students based on name
 Delete the students whose score is less than 10
 And get the students whose score is max in tree.
In main function create the object array of students with 10 students from those store 7
seven students randomly and perform all above objects.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student
{
    string name;
    int roll;
    int score;
    Student() {}
    Student(string n, int r, int s) : name(n), roll(r), score(s) {}
};

struct Node
{
    Student s;
    Node *left, *right;
    Node(Student x) : s(x), left(NULL), right(NULL) {}
};

Node *insertNode(Node *root, Student x)
{
    if (!root)
        return new Node(x);
    if (x.name < root->s.name)
        root->left = insertNode(root->left, x);
    else if (x.name > root->s.name)
        root->right = insertNode(root->right, x);
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, string name)
{
    if (!root)
        return root;
    if (name < root->s.name)
        root->left = deleteNode(root->left, name);
    else if (name > root->s.name)
        root->right = deleteNode(root->right, name);
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
            root->s = temp->s;
            root->right = deleteNode(root->right, temp->s.name);
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->s.name << " (Roll " << root->s.roll << ", Score " << root->s.score << ")\n";
    inorder(root->right);
}

Node *searchNode(Node *root, string name)
{
    if (!root || root->s.name == name)
        return root;
    if (name < root->s.name)
        return searchNode(root->left, name);
    return searchNode(root->right, name);
}

Node *deleteLowScores(Node *root)
{
    if (!root)
        return NULL;
    root->left = deleteLowScores(root->left);
    root->right = deleteLowScores(root->right);
    if (root->s.score < 10)
        root = deleteNode(root, root->s.name);
    return root;
}

void findMaxScore(Node *root, Student &maxS)
{
    if (!root)
        return;
    if (root->s.score > maxS.score)
        maxS = root->s;
    findMaxScore(root->left, maxS);
    findMaxScore(root->right, maxS);
}

int main()
{
    srand(time(0));
    Student arr[10] = {
        {"Ali", 1, 15}, {"Bilal", 2, 8}, {"Hassan", 3, 25}, {"Sara", 4, 5}, {"Usman", 5, 18}, {"Omer", 6, 12}, {"Zara", 7, 28}, {"Daniyal", 8, 9}, {"Baqar", 9, 22}, {"Hamza", 10, 30}};

    Node *root = NULL;
    bool used[10] = {false};
    for (int i = 0; i < 7; i++)
    {
        int idx;
        do
        {
            idx = rand() % 10;
        } while (used[idx]);
        used[idx] = true;
        root = insertNode(root, arr[idx]);
    }

    cout << "BST (Inorder Traversal):\n";
    inorder(root);

    cout << "\nEnter name to search: ";
    string n;
    cin >> n;
    Node *found = searchNode(root, n);
    if (found)
        cout << "Found: " << found->s.name << " (Score " << found->s.score << ")\n";
    else
        cout << "Not found\n";

    cout << "\nDeleting students with score < 10...\n";
    root = deleteLowScores(root);
    cout << "BST after deletion:\n";
    inorder(root);

    Student maxS("", 0, -1);
    findMaxScore(root, maxS);
    cout << "\nStudent with max score: " << maxS.name << " (Roll NO " << maxS.roll << ", Score " << maxS.score << ")\n";

    return 0;
}
