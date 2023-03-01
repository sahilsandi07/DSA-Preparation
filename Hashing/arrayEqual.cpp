#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int cnt = 0;
        
        for(int i = 0; i<N; i++){
            if (A[i] == B[i]){
                cnt ++;
            }
        }
        if (cnt == N){
            return true;
        }
        else {
            return false;
        }
    }
};

int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {5,4,3,2,1};
    int n = 5;

    Solution obj;
    if (obj.check(a,b,n) == true){
        cout << "Arrays are Equal!" << endl;
    }

    else {
        cout << "Arrays are not equal!" << endl;
    }
    return 0;
}