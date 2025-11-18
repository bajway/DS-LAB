#include <iostream>
using namespace std;

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

void convertToMaxHeap(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
}

int main() {
    int a[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(a)/sizeof(a[0]);

    convertToMaxHeap(a, n);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
