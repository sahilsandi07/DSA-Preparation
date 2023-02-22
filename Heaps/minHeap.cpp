#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){

    int smallest = i;
    int left_index = 2*i + 1;
    int right_index = 2*i + 2;

    if (left_index < n && arr[smallest] > arr[left_index]){
        smallest = left_index;
    }

    if (right_index < n && arr[smallest] > arr[right_index]){
        smallest = right_index;
    }

    if (smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
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