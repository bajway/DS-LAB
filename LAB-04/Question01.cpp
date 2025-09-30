#include<iostream>
using namespace std;

void selectionSort(int arr[], int s){
    for (int i = 0; i < s-1; i++){
        int minIndex = i;
        for (int j = i + 1; j < s; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
    }
}
int main(){
    int size = 10;
    int array[size];
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];
    selectionSort(array, size);
    cout << "Four Minimum Elements: " << endl;
    for (int i = 0; i < 4; i++)
        cout << array[i] << " ";
}