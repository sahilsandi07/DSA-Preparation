#include <bits/stdc++.h> 
using namespace std;

void print (vector<vector<int>> arr){

    for (int i=0; i<arr.size(); i++){
        if (i % 2 == 0){
            for (int j=0; j<arr[i].size(); j++){
                cout << arr[i][j] << " ";
            }
        }
            
        else{
            for (int j=arr[i].size()-1; j>=0; j--){
                cout << arr[i][j] << " ";
            }
        } 
    }

}

int main(){

    vector<vector<int>> arr = {{1,2,3},{4,5,6,7},{8,9,10,11,12}};

    print (arr);
    return 0;

}