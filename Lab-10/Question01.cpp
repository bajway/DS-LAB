#include <iostream>
using namespace std;

class MinMaxHeap {
    int heap[100];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        if (i == 0) return;
        int p = parent(i);
        if (i % 2 == 0) { // Even index -> max level
            if (heap[i] > heap[p]) {
                swap(heap[i], heap[p]);
                heapifyUp(p);
            }
        } else { // Odd index -> min level
            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                heapifyUp(p);
            }
        }
    }

    void heapifyDownMin(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDownMin(smallest);
        }
    }

    void heapifyDownMax(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDownMax(largest);
        }
    }

    void heapifyDown(int i) {
        if (i % 2 == 0) heapifyDownMax(i); // max level
        else heapifyDownMin(i);            // min level
    }

public:
    MinMaxHeap() { size = 0; }

    void insert(int val) {
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) return;
        int old_val = heap[i];
        heap[i] = new_val;
        if (new_val > old_val) heapifyUp(i);
        else heapifyDown(i);
    }

    void delete_key(int i) {
        if (i < 0 || i >= size) return;
        heap[i] = heap[size - 1];
        size--;
        heapifyDown(i);
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinMaxHeap h;
    int values[] = {8, 7, 6, 5, 4};
    for (int i = 0; i < 5; i++)
        h.insert(values[i]);

    cout << "Initial Min-Max Heap: ";
    h.printHeap();

    h.update_key(2, 10);
    cout << "After update_key(2, 10): ";
    h.printHeap();

    h.delete_key(1);
    cout << "After delete_key(1): ";
    h.printHeap();

    return 0;
}
