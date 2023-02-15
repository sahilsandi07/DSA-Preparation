#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m){
    vector<int> merged(n+m);
        
    for (int i=0; i<n; i++){
        merged[i] = arr1[i];
    }
        
    int j=n;
    for (int i=0; i<m; i++){
        merged[j] = arr2[i];
        j++;
    }
        
    sort(merged.begin(),merged.end());
        
    for(int i=0; i<n; i++){
        arr1[i] = merged[i];
    }
        
    int k = n;
    for (int i=0; i<m; i++){
        arr2[i] = merged[k];
        k++;
    }
}

int main(){
    int a[]= {1,5,7,9,81};
    int b[]= {2,4,5,6,7};
    int n=5,m=5;
    
    merge(a,b,n,m);
    
    for (int i=0; i<n; i++){
        cout << a[i] <<" ";
    }

    for (int i=0; i<m; i++){
        cout << b[i] <<" ";
    }
    cout << endl;
}