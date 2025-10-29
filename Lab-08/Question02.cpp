/*Question 02: Reuse the methods from above question 1 and complete below question:
You are required to implement a game titled “BattleQuest: BST Arena” using a Binary
Search Tree (BST) where each node in the tree stores a Combatant object. This
game simulates a classic RPG-style battle between a player’s team of heroes and a
team of enemies. The core challenge involves managing two separate BSTs — one for
the player’s team and another for the enemy team — where each node contains a
Combatant object with attributes such as name, health points (HP), and attack power.......*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant
{
    string name;
    int hp;
    int attack;
    Combatant() {}
    Combatant(string n, int h, int a) : name(n), hp(h), attack(a) {}
};

struct Node
{
    Combatant c;
    Node *left, *right;
    Node(Combatant x) : c(x), left(NULL), right(NULL) {}
};

Node *insertNode(Node *root, Combatant x)
{
    if (!root)
        return new Node(x);
    if (x.name < root->c.name)
        root->left = insertNode(root->left, x);
    else if (x.name > root->c.name)
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
    if (name < root->c.name)
        root->left = deleteNode(root->left, name);
    else if (name > root->c.name)
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
            root->c = temp->c;
            root->right = deleteNode(root->right, temp->c.name);
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->c.name << "(" << root->c.hp << ") ";
    inorder(root->right);
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

Node *getFrontline(Node *root)
{
    return findMin(root);
}

int main()
{
    srand(time(0));
    Node *heroes = NULL;
    Node *enemies = NULL;

    heroes = insertNode(heroes, Combatant("Bajwa", 30, 7));
    heroes = insertNode(heroes, Combatant("Baqar", 35, 6));
    heroes = insertNode(heroes, Combatant("Bohemia", 25, 8));
    heroes = insertNode(heroes, Combatant("BigMan", 40, 5));
    heroes = insertNode(heroes, Combatant("Basit", 28, 7));

    enemies = insertNode(enemies, Combatant("Anwer", 25, 5));
    enemies = insertNode(enemies, Combatant("Talibaans", 30, 6));
    enemies = insertNode(enemies, Combatant("CT", 40, 4));
    enemies = insertNode(enemies, Combatant("team T", 28, 7));
    enemies = insertNode(enemies, Combatant("Omer", 35, 5));

    int round = 1;
    while (!isEmpty(heroes) && !isEmpty(enemies))
    {
        cout << "\nRound " << round++ << "\n";
        cout << "Heroes: ";
        inorder(heroes);
        cout << "\nEnemies: ";
        inorder(enemies);
        cout << "\n";

        Node *hero = getFrontline(heroes);
        Node *enemy = getFrontline(enemies);

        int hDamage = hero->c.attack + rand() % 5;
        enemy->c.hp -= hDamage;
        cout << hero->c.name << " attacks " << enemy->c.name << " for " << hDamage << " damage.\n";
        if (enemy->c.hp <= 0)
        {
            cout << enemy->c.name << " has been defeated!\n";
            enemies = deleteNode(enemies, enemy->c.name);
            if (isEmpty(enemies))
                break;
        }

        if (!isEmpty(enemies))
        {
            enemy = getFrontline(enemies);
            int eDamage = enemy->c.attack + rand() % 5;
            hero->c.hp -= eDamage;
            cout << enemy->c.name << " counterattacks " << hero->c.name << " for " << eDamage << " damage.\n";
            if (hero->c.hp <= 0)
            {
                cout << hero->c.name << " has been defeated!\n";
                heroes = deleteNode(heroes, hero->c.name);
            }
        }
    }

    if (isEmpty(heroes) && isEmpty(enemies))
        cout << "\nDraw!\n";
    else if (isEmpty(enemies))
        cout << "\nVictory!!! All enemies defeated!\n";
    else
        cout << "\n Defeat :( All heroes defeated!\n";

    return 0;
}
