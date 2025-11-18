#include <iostream>
using namespace std;

bool isHeap(int a[], int n) {
    for (int i = 0; i <= (n-2)/2; i++) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[i] < a[l]) return false;
        if (r < n && a[i] < a[r]) return false;
    }
    return true;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSortAscending(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i > 0; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

int main() {
    int a[] = {8,7,6,5,4};
    int n = sizeof(a)/sizeof(a[0]);

    if (isHeap(a, n)) cout << "It is a Max Heap\n";
    else cout << "It is NOT a Max Heap\n";

    heapSortAscending(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
