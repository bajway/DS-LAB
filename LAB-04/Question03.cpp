/*Given an array of strings arr[]. Sort given strings using Bubble Sort and display the
sorted array.
Input: string arr[] = {"banana", "apple", "cherry", "date", "grape"};
Output: apple banana cherry date grape*/

#include<iostream>
#include<string>
using namespace std;

void sortArray(string arr[], int s){
    for (int i = 0; i < s; i++){
        for (int j = i; j < s - 1; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(){
    string arr[] = {"banana", "apple", "cherry", "date", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size);
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}