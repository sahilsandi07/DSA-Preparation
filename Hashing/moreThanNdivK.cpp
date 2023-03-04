#include<bits/stdc++.h>
using namespace std;

void moreThanNbyK(int arr[], int n, int k){
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    for (auto it: mp){
        
        if (it.second > n/k){
            cout << "The Count of " << it.first << " is " << it.second <<" Which is more Than " << n/k << endl;
        }
    }
}

int main(){
    int arr[] = {10, 11, 21, 23, 11, 12, 10, 11, 11, 10, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    moreThanNbyK(arr, n, k);
}