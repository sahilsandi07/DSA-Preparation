// User function Template for C++

class Solution{
  public:
    int majorityWins(int arr[], int n, int x, int y) {
        
        int freq_x = 0; 
        int freq_y = 0; 
      
        for (int i = 0; i < n; i++) 
        { 
            if (arr[i] == x) 
                freq_x++; 
      
            if (arr[i] == y) 
                freq_y++; 
        } 
      
        if (freq_x > freq_y) 
            return x; 
      
        if (freq_y > freq_x) 
            return y; 
      
        if (freq_x == freq_y) 
        { 
            if (x < y) 
                return x; 
            else
                return y; 
        } 
        
    }
};