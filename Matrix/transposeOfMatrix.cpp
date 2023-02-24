#include<bits/stdc++.h>
using namespace std;

void printTranspose(vector<vector<int>> arr){

    for (int i=0; i<arr.size(); i++){
        for (int j=i+1; j<arr[i].size(); j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i=0; i<arr.size(); i++){
        for (int j=0; j<arr.size(); j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }

}

int main(){
    
    vector<vector<int>> arr = {{1,2,3}, {4,5,6}, {7,8,9}};
    printTranspose(arr);
    return 0;

}