class Solution{
    public:
    int peakElement(int a[], int n){
        int low=0, high=n-1;
        while (low<=high){
            int mid=(low+high)/2;
            if (mid==0 || a[mid-1]<=a[mid] && mid==n-1 || a[mid+1]<=a[mid]){
                return mid;
            }
            if(mid>0 && a[mid-1]>=a[mid]){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
    }
};

class Solution1{
    public:
    int peakElement(int arr[], int n){
        int l = 0, r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])) return mid;
                
            else if(mid > 0 && arr[mid-1] > arr[mid]) r = mid-1;
                
            else l = mid+1;
                
        }
        return 0;
    }
};