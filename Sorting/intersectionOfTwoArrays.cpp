#include<bits/stdc++.h>
using namespace std;

void intersection(int a[], int b[], int n, int m){
    for (int i=0; i<n; i++){
        if (i>0 && a[i]==a[i-1]){
            continue;
        }

        for (int j=0; j<m; j++){
            if (a[i]==b[j]){
                cout<<a[i]<<" ";
                break;
            }
        }
    }
}

int main(){
    int a[] = {12,12,2,3,4,2,32,1,23,123,124,43132,2};
    int b[] = {12,4,56,74,46,3545,6,565,6};
    int n = 13;
    int m = 9;
    intersection(a,b,n,m);
    return 0; 
}