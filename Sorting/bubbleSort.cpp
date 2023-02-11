#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        bool swapped = false;

        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
                swapped = true; 
        }

        if (swapped == false)
            break;
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
    bubbleSort(arr,n);
    printArray(arr,n);
}