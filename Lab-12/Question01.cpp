#include<iostream>
using namespace std;

int main(){
    char text[]="the quick brown fox jumps over the lazy dog";
    char pattern[]="the";

    int n=0,m=0,i,j;
    while(text[n]!='\0') n++;
    while(pattern[m]!='\0') m++;

    int comparisons=0;
    int result[50];
    int k=0;

    for(i=0;i<=n-m;i++){
        j=0;
        while(j<m && text[i+j]==pattern[j]){
            comparisons++;
            j++;
        }
        if(j<m) comparisons++;
        if(j==m){
            result[k]=i;
            k++;
        }
    }

    for(i=0;i<k;i++){
        cout<<result[i]<<" ";
    }
    cout<<"\n"<<comparisons;
}
