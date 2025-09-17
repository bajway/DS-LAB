/*Write a Program that ask user to enter 10 elements and finds the 4 minimum elements
from given array using selection Sort.*/

#include<iostream>

using namespace std;

void selectionSort(int arr[], int s ){
        for(int i=0; i<s; i++){
            int minIndex= i;
            for(int j=i+1; j<s-1; j++){
                if(arr[j]< arr[minIndex]){
                    minIndex= j;
                }
            }
            int temp= arr[i];
            arr[i]= arr[minIndex];
            arr[minIndex]= temp;
        }
        
    }

int main(){
    int size=10;
    int arr[size];
    cout<< "Enter the elements: ";
    for(int i=0; i<size; i++){
        cout<< "Element "<< i+1<< " :";
        cin>> arr[i];
    }   
    selectionSort(arr, size);
    for(int i=0; i<4; i++){
        cout<< arr[i]<< " ";
    }
}
