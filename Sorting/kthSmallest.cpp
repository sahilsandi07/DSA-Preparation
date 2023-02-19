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

void  kthSmallest(int arr[], int n, int k){
    int low  = 0, high = n-1;

    while (low <= high){
        int pivot = lomuto(arr, low, high);

        if (pivot == k-1){
            cout << "K'th Smallest Element is: " << arr[pivot] << endl;
            break;
        }

        else if (pivot > k-1){
            high = pivot - 1;
        }

        else {
            low = pivot + 1;
        }
    }
}

int main(){

    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    kthSmallest(arr, n, k);

}