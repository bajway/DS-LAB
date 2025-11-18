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

int kthLargest(int a[], int n, int k) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i >= n-k; i--) {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
    return a[n-k];
}

int main() {
    int a[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    cout << kthLargest(a, n, k);
}
