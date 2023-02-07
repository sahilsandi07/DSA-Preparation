class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
         int rs=0;
         for(int i=0; i<n; i++){
             rs+=a[i];
         }
         
         int ls=0;
         for (int i=0; i<n; i++){
             rs-=a[i];
             if (ls==rs){
                return i+1;
             }
             ls+=a[i];
         }
         return -1;
    }

};