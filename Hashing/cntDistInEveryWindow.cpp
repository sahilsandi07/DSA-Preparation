#include<bits/stdc++.h>
using namespace std;

void cntDistinct(int arr[], int n, int k){
    unordered_map<int, int> mp;
    for  (int i=0; i<k; i++){
        mp[arr[i]]++;
    }
    cout << mp.size() << endl;

    for (int i=k; i<n; i++){
        mp[arr[i-k]]--;
        if (mp[arr[i-k]] == 0){
            mp.erase(arr[i-k]);
        }
        mp[arr[i]]++;

        cout << mp.size() << endl;
    }
}




int main(){
    int arr[] = {10, 10, 5, 3, 20, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cntDistinct(arr, n, k);
}