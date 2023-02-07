#include<iostream>
using namespace std;

class Solution{
    public:
    int sorted_rotated(int arr[], int N, int X){
        int low=0, high=N-1;

        while (low<=high){
            int mid=(low+high)/2;
            if (arr[mid]==X){
                return mid;
            }

            if (arr[mid]>arr[low]){
                if (X>=arr[low] && X<arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            else{
                if (X>arr[mid] && X<=arr[high]){
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n;
        
        int a[n];

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        cin>>x;

        Solution obj;

        cout<<obj.sorted_rotated(a,n,x)<<endl;
    }
    return 0;
}