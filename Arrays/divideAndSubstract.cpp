//User function Template for C++

class Solution {
  public:
    string divAndSub(int N) {
        if(N == 1)
            return "Arya";
        // 1 if Arya wins , 0 otherwise.
        vector<int> dp(N+1);
        // Arya wins as no player can mov.
        // and is bob's turn
        dp[0] = 1;
        
        // possible move space.
        vector<int> mov = {2, 3, 4, 5};
        for(int i = 6; i <= N; i++){
            
            // Whether Arya won in any one of previous states.
            bool canwin = 0;
            
            // if for all of the previous states that is:
            // states = {n-2, n-3, n-4, n-5,n/2, n/3, n/4, n/5}
            // if arya cannot wins. Then arya can make
            // a move to any of these states such that its john turn now.
            // Note that as one more move was added because we moved 
            // from n to states[i] so if arya was loosing in all of these 
            // states[i]. Then conversely arya will win at 'n'.
            for(auto k : mov){
                if(i-k >= 0)
                    canwin |= dp[i-k];
                canwin |= dp[i/k];
            }
            
            // dp[i] = 1 (Arya wins)
            dp[i] = canwin^1;
        }
        return (!dp[N] ? "Jon" : "Arya");
    }
};