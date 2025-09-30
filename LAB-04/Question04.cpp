#include<iostream>
using namespace std;

bool isDuplicate(int arr[], int size){
    bool found = false;
    for (int i = 0; i < size; i++){
        
        for (int j = i; j < size - 1; j++){
            if(arr[j]==arr[j+1])
                found = true;
                break;
            
        }

    }
    return found;
}
int main(){
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size;i++){
        cin >> array[i];
    }
    if(isDuplicate(array, size)){
        cout << "The array contains duplicates" << endl;
    }
    else cout << "No duplicates Found in Array" << endl;
    return 0;
}