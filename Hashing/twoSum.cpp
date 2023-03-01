#include<bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int N, int sum) {
    unordered_set<int> s;
    
    for (int i=0; i<N; i++){
        if (s.find(sum-arr[i]) != s.end()){
            return 1;
            break;
        }
        s.insert(arr[i]);                   
    }
    
    return 0;
    
}

int main(){
    int a[] = {2,3,1,2,3,4,45,1,2,34,3};
    int n = 11;
    int sum = 36;

    if (sumExists(a,n,sum) == 1){
        cout << "Pairs Exist1" <<endl;
    }
    else{
        cout <<"No Pair Exist" << endl;
    }
}