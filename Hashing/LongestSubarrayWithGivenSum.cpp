#include <bits/stdc++.h>
using namespace std; 

int largestSubarrayWithSumX(int arr[], int n, int sum) { 
    int prefix_sum = 0, res = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        prefix_sum += arr[i];
        if(prefix_sum == sum)
            res = i + 1; 
        if(m.find(prefix_sum) == m.end())
            m.insert({prefix_sum, i}); 
        if(m.find(prefix_sum - sum) != m.end())
            res = max(res, i-m[prefix_sum-sum]);
    }
    return res;
}
        
int main() {
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;
    cout << "The Length of Longest subArray with given Sum is: " << largestSubarrayWithSumX(arr, n, sum);
}