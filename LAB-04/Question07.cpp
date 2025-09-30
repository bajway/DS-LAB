#include<iostream>
#include<string>
using namespace std;

void  searchNameUsingLinearSearch(string arr[], int s, string name[] ){
    
    for (int i = 0; i < 3;i++){
        bool found = false;
        for (int j = 0; j < s; j++){
            if (name[i] == arr[j])
            {
                cout << name[i] << " Found after " << j+1 << " steps" << endl;
                found = true;
                break;
            }
        
        }
        if(!found)
            cout << name[i] << " Not Found after " << s<< " steps"<< endl;
    }
    
    
}
int searchNameUsingBinarySearch(string arr[], int s, string target){
    int left = 0, right = s - 1;
    int count = 0;
    while(left<=right){
        count++;
        int mid = left + (right - left) / 2;
        if(arr[mid]==target){
            cout << target << " found after " << count << " steps" << endl;
            return mid;
        }
        else if(arr[mid]< target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << target << " not found after " << count << " steps" << endl;
    return -1;
}
int  main(){
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Toufiq",
                    "Yasin", "Zulfiqar"};
    string searchName[] = {"Aftab", "Rizwan", "Tariq"};
    int size = sizeof(arr) / sizeof(arr[0]);
    searchNameUsingLinearSearch(arr, size, searchName);
    cout << "\n\nUsing Binary Search\n\n";
    for (int i = 0; i < 3; i++){
        searchNameUsingBinarySearch(arr, size, searchName[i]);
    }
}