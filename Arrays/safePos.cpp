class Solution {
  public:
    int safePos(int n, int k) {
        int i=1,res{};
        while(i!=n) res=(res+k)%(++i);
        return res+1;
    }
};
