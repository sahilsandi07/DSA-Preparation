#include <bits/stdc++.h>
using namespace std;

void selectSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        int min_index = i;

        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min_index])
                min_index = j;
            swap(arr[min_index], arr[i]); // if you use swap(arr[min_index], arr[j]), it will sort the array in decresing order;
        }
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
    selectSort(arr,n);
    printArray(arr,n);
}