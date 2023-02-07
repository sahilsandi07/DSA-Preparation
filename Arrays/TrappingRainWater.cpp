
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        long long ans = 0;
        int left = 0, right = n-1, leftMax = arr[0], rightMax = arr[n-1];
        while(left < right){
            if(leftMax <= rightMax){
                left++;
                leftMax = max(leftMax, arr[left]);
                ans += leftMax - arr[left];
            }
            else{
                right--;
                rightMax = max(rightMax, arr[right]);
                ans += rightMax - arr[right];
            }
        }
        return ans;
    }
};