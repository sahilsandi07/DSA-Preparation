class Solution{
    public:
    bool isPair(int a[], int n, int x){
        int i=0, j=n-1;
        while(i<j){
            if(a[i]+a[j]==x){
                return true;
            }
            else if((a[i]+a[j])>x){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};