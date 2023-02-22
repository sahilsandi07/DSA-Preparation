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

    cout << endl;

    cout << "Printing Max Heap Using Priority Queue" << endl;

    // Max Heap

    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(2);
    pq.push(12);
    pq.push(13);

    cout << "Element at top is: " << pq.top() <<endl;
    pq.pop();
    cout << "Modified Element at top is: " << pq.top() <<endl;
    cout << "Size is: " << pq.size() << endl;
    if (pq.empty()){
        cout << "Queue is Empty!" << endl;
    }
    else{
        cout <<"Queue is not Empty!" << endl; 
    }

    // Min Heap 
    cout << endl;
    cout << "Printing Min Heap using Priority Queue" << endl;

    priority_queue<int, vector<int>, greater<int>> mih;
    mih.push(1);
    mih.push(4);
    mih.push(3);
    mih.push(2);
    mih.push(12);
    mih.push(13);

    cout << "Element at top is: " << mih.top() <<endl;
    mih.pop();
    cout << "Modified Element at top is: " << mih.top() <<endl;
    cout << "Size is: " << mih.size() << endl;
    if (mih.empty()){
        cout << "Queue is Empty!" << endl;
    }
    else{
        cout <<"Queue is not Empty!" << endl; 
    }



    return 0;

}