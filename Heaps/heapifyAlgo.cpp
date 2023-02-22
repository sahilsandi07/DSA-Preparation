#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){

    int largest = i;
    int left_index = 2*i;
    int right_index = 2*i + 1;

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

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    for (int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;

}