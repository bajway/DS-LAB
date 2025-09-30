#include<iostream>
using namespace std;

void sortAcBirthYear(int arr[], int s){
    //using Bubble Sort
    for (int i = 0; i < s; i++){
        for (int j = i; j < s-1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(){
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortAcBirthYear(arr, size);
   
    for (int i = 0; i < size; i++){
        cout <<  arr[i] << " ";
    }
    
    return 0;
}