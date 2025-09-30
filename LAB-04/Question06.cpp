/*. Implement the array given in the heading of binary search topic, sort it and find the
value corresponding to to your last two digits of the roll number
(if its not in the array add a value somewhere in between the array) and find it via binary search.*/

#include<iostream>
using namespace std;

void sortArray(int arr[], int s){
    //using bubbleSort
    for (int i = 0; i < s-1; i++){
        for (int j = 0; j < s-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int searchRollNo(int arr[], int s, int target){
    int left = 0, right = s - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(arr[mid]==target){
            cout << target << " exists in the array!" << endl;
            return mid;
            
        }
        else if(arr[mid]<target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << target << " does not exists in the array" << endl;
    return -1;
}
//P.S : assumed the array with one entry as my roll number as the array wa not given.

int main(){

    int size;
    cin >> size;
    int array[size];
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    sortArray(array, size);
    searchRollNo(array, size, 39); //roll no: 24k-2539
    return 0;
}