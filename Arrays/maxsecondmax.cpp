     

class Solution{
  public:
    /* Function to find largest and second largest element
    *sizeOfArray : number of elements in the array
    * arr = input array
    */
    
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        vector<int> result;
        int max = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < sizeOfArray; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        bool allSame = true;
        for (int i = 0; i < sizeOfArray; i++) {
            if (arr[i] > max2 && arr[i] < max) {
                max2 = arr[i];
                allSame = false;
            }
        }
        if (allSame) {
            max2 = -1;
        }
        result.push_back(max);
        result.push_back(max2);
        return result;
    }
};