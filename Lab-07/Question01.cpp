#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string name;
    int score;
    Node* next;

    Node(string n, int s) 
    {
        name = n;
        score = s;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;

    int getMax(){
        int maxVal = head->score;
        Node* temp = head;
        while (temp){
            if (temp->score > maxVal)
                maxVal = temp->score;
            temp = temp->next;
        }
        return maxVal;
    }

    int getDigit(int number, int exp){
        return (number / exp) % 10;
    }

    void countingSort(int exp){
        Node* outputHead = nullptr;
        Node* outputTail = nullptr;
        Node* buckets[10] = {nullptr};
        Node* bucketTails[10] = {nullptr};
        Node* temp = head;

        while (temp){
            int digit = getDigit(temp->score, exp);
            Node* newNode = new Node(temp->name, temp->score);
            if (!buckets[digit]){
                buckets[digit] = bucketTails[digit] = newNode;
            } 
            else{
                bucketTails[digit]->next = newNode;
                bucketTails[digit] = newNode;
            }
            temp = temp->next;
        }

        for (int i = 0; i < 10; i++) {
            if (buckets[i]){
                if (!outputHead){
                    outputHead = buckets[i];
                    outputTail = bucketTails[i];
                } 
                else{
                    outputTail->next = buckets[i];
                    outputTail = bucketTails[i];
                }
            }
        }

        head = outputHead;
    }

public:
    LinkedList() { head = nullptr; }

    void insert(string name, int score) {
        Node* newNode = new Node(name, score);
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void radixSort() {
        if (!head || !head->next)
            return;
        int maxVal = getMax();
        for (int exp = 1; maxVal / exp > 0; exp *= 10)
            countingSort(exp);
    }

    void display() {
        Node* temp = head;
        cout << "Name\tScore\n";
        cout << "----------------\n";
        while (temp) {
            cout << temp->name << "\t" << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.insert("Ali", 92);
    list.insert("Sara", 75);
    list.insert("Umer", 88);
    list.insert("Ayesha", 60);
    list.insert("Bilal", 99);
    list.insert("Hina", 70);

    cout << "Before Sorting:\n";
    list.display();

    list.radixSort();

    cout << "\nAfter Sorting (Ascending by Score):\n";
    list.display();

    return 0;
}
