#include <bits/stdc++.h>
using namespace std;
// We are considering 0 based indexing here

void heapify(int arr[], int n, int i){

    int largest = i;
    int left_index = 2*i + 1;
    int right_index = 2*i + 2;

    if (left_index < n && arr[largest] < arr[left_index]){
        largest = left_index;
    }

    if (right_index < n && arr[largest] < arr[right_index]){
        largest = right_index;
    }

    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

void buildHeap(int arr[], int  n){
    for (int i=n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    int size = n;

    while (size > 1){

        // step 1: swap root with last element
        swap(arr[size-1], arr[0]);
        size--;

        // step 2: Put root to its right position
        heapify(arr, size, 0);
    }
}

int main(){

    int arr[] = {54, 53, 55, 52, 50, 123};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Call heap sort function
    heapSort(arr, n);

    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;

}