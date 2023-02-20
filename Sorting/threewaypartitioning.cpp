#include<bits/stdc++.h>
using namespace std;

//Dutch National Flag Algorithm

void threeWay(int arr[], int a, int b, int n){

    int low = 0, mid = 0, high = n-1;

    while (mid <= high){

        if (arr[mid] < a){
            swap(arr[mid++], arr[low++]);
        }

        else if (arr[mid] > b){
            swap(arr[mid], arr[high--]);
        }

        else {
            mid++;
        }

    }
    //swap(a,b);

    for (int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;

}

int main(){
    
    int arr[] = {2,31,23,5,4,32,12};
    int a = 5, b =23;

    int n = sizeof(arr)/sizeof(arr[0]);

    threeWay(arr, a, b, n);
}