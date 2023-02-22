#include <bits/stdc++.h>
using namespace std;

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

int main(){

    int arr[] = {54, 53, 55, 52, 50, 123};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
    }

    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;

}