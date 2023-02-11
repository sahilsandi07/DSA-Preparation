#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for (int i=1; i<n; i++){
        
        int key = arr[i];   // variable to store modified values

        int j = i-1;
        while (j>=0 && arr[j] > key){    // initializing a loop to modify the values 
            arr[j+1] = arr[j];           // ex. [1,2,5,6,3] to move 3 befor 5
            j--;                            
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {12,3,4,53,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    printArray(arr,n);
}