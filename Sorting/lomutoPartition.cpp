#include<bits/stdc++.h>
using namespace std;

void lomuto_partition(int arr[], int left_index, int right_index){

    int pivot_element = arr[right_index];

    int iterator = left_index - 1;

    for (int j = left_index; j <= right_index-1; j ++){

        if (arr[j] < pivot_element){

            iterator++;
            swap(arr[iterator], arr[j]);

        }

    }

    swap (arr[iterator+1], arr[right_index]);

    //cout << arr[pivot_index] << endl;
    
    for (int i = 0; i < right_index+1; i++){
        cout << arr[i] <<" ";
    } 
    cout << endl;

    for (int i = 0; i < right_index+1; i++){
        if (arr[i] == pivot_element){
            cout << i <<" ";
            break;
        }
    }

    //return iterator+1;
}

int main(){

    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n=sizeof(arr)/sizeof(arr[0]);

    lomuto_partition(arr, 0, n-1);

}