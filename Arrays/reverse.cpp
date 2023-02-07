//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        for(long long i = 0;i<n;i+=k){ 
            
            //If (ith index +k) is less than total number of elements it means
            //k elements exist from current index so we reverse k elements 
            //starting from current index.
            if(i+k < n){ 
                //reverse function used to reverse any part of the array.
                reverse(arr.begin()+i, arr.begin()+(i+k));
            }
            
            //Else k elements from current index doesn't exist. 
            //In that case we just reverse the remaining elements.
            else{
                //reverse function used to reverse any part of the array.
                reverse(arr.begin()+i, arr.end());
            }
        }
    }
};