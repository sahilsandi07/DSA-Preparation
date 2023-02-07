class Solution{
    public:
        int maxOccured(int L[], int R[], int n, int maxx) {
        int i, max = 0, res = 0;
        int arr[1000001] = {0};
    
        for (i = 0; i < n; i++) {
            ++arr[L[i]];
            --arr[R[i] + 1];
        }
    
        max = arr[0];
        for (i = 1; i <= maxx; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] > max) {
                max = arr[i];
                res = i;
            }
        }
    
        return res;
    }

    
};