#include<bits/stdc++.h>
using namespace std;

//Efficient Approach  
// Time Complexity: O(n+m)

void intersection(int a[], int b[], int n, int m){
    int i = 0, j = 0;

    while (i<n && j<m){
        if (i > 0 && a[i]==a[i-1]){
            i++;
            continue;
        }

        if (a[i] < b[j]){
            i++;
        }

        if (a[i] > b[j]){
            j++;
        }

        if (a[i] == b[j]){
            cout << a[i] <<" ";
            i++;
            j++;
        }
    }
}

int main(){
    int a[] = {1,1,1,2,2,2,2,2,2,4,4,4,4};
    int b[] = {1,2,3,4,5,6,7,8,9};
    int n = 13;
    int m = 9;
    intersection(a,b,n,m);
    return 0; 
}