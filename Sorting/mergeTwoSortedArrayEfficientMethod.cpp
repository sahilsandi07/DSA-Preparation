#include<bits/stdc++.h>
using namespace std;

//Time Complexity is O((n+m)log(n+m))
//The Algorithm is Written by me And I have alll rights of it.

void merge(int arr1[], int arr2[], int n, int m){
    vector<int> merged(n+m);

    //copy elements of array 1 to vector merged for position 0 t0 n-1 
    for (int i=0; i<n; i++){
        merged[i] = arr1[i];
    }

    //copy elements of array 2 to vector merged for position n-1 t0 m
    int j=n;
    for (int i=0; i<m; i++){
        merged[j] = arr2[i];
        j++;
    }

    //sort the merged vector    
    sort(merged.begin(),merged.end());

    //copy the sorted values from merged vector to array 1    
    for(int i=0; i<n; i++){
        arr1[i] = merged[i];
    }

    //copy the sorted values from merged vector to array 2    
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