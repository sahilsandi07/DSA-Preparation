#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2,1,3,4,6,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int cs=0; cs<n-1; cs++){
        int item = arr[cs];
        int pos = cs;

        for (int i=cs+1; i<n; i++){
            if (arr[i] < item){
                pos++;
            }
        }
        swap(item, arr[pos]);

        while (pos != cs){
            pos = cs;
            for (int i=cs+1; i<n; i++){
                if (arr[i] < item){
                    pos++;
                }
            }
            swap (item, arr[pos]);
        }
    }
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}