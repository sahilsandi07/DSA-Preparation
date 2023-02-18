#include <bits/stdc++.h>
using namespace std;

int lomuto(int arr[], int left_ind, int right_ind){
    int pivot = right_ind;

    int i = left_ind - 1;

    for (int j=left_ind; j<=right_ind-1; j++){
        if (arr[j] < arr[pivot]){
            i++;
            swap (arr[i], arr[j]);
        }
    }  

    swap (arr[i+1], arr[right_ind]);

    return i+1;

}

int QuickSort(int arr[], int left_ind, int right_ind){
    
    if (left_ind < right_ind){

        int pivot = lomuto (arr, left_ind, right_ind);

        // sort left half around the pivot
        QuickSort(arr, left_ind, pivot-1);

        // sort right half around the pivot
        QuickSort(arr, pivot+1, right_ind);

    }
}

void print (int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int main(){

    int arr[] = {1,0,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr, 0, n-1);
    lomuto(arr, 0, n-1);
    print (arr,n);
}