/*Task#2: Let arr[9] = { 20, 12, 15, 2, 10, 1, 13, 9, 5} now sort the array in such a way that
maximum element must be at middle of the array and rest of array must be sorted in ascending
order do this using insertion sort.
Sorted array: 1 2 5 9 20 10 12 13 15*/
#include <iostream>
using namespace std;

void sortArray(int arr[], int s)
{
    int mid = s / 2;
    // using insertion sort
    for (int i = 1; i < s; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    int maxVal = arr[s - 1];
    for (int i = s - 1; i > mid; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[mid] = maxVal;
}

int main()
{
    int array[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    int size = sizeof(array) / sizeof(array[0]);
    sortArray(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}