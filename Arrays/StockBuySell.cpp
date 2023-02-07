

//User function Template for Java

class Solution{
    //Function to find the days of buying and selling stock for max profit.
    ArrayList<ArrayList<Integer> > stockBuySell(int arr[], int n) {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(i-1);
                temp.add(i);
                ans.add(temp);
            }
        }
        return ans;
    }
}