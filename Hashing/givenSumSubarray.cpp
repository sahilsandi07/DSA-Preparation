class Solution {
public:
    int subArraySum(int arr[], int n, int sum) {
        unordered_map<int, int> freq;
        int psum = 0;
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            psum += arr[i];
            if (psum == sum) {
                cnt++;
            }
            if (freq.find(psum - sum) != freq.end()) {
                cnt += freq[psum - sum];
            }
            freq[psum]++;
        }
        
        return cnt;
    }
};