class Solution {
  public:
    long long int countAndMerge(long long arr[], long long l, long long m, long long r)
    {
        long long n1=m-l+1, n2=r-m;
        long long left[n1],right[n2];
        for(int i=0;i<n1;i++)
            left[i]=arr[i+l];
        for(int j=0;j<n2;j++)
            right[j]=arr[m+1+j];    
        long long res=0,i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(left[i]<=right[j])
                {arr[k++]=left[i++];}
            else{
                arr[k++]=right[j++];
                res=res+(n1-i);
            }
        }
        while(i<n1)
            arr[k++]=left[i++];
        while(j<n2)
            arr[k++]=right[j++];
        return res;
    }
    
    long long int countInv(long long arr[], long long l, long long r)
    {
        long long res = 0;
        if (l<r) {
           
            long long m = (r + l) / 2;
     
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += countAndMerge(arr, l, m , r);
        }
        return res;
    }

    long long int inversionCount(long long arr[], long long N) {

        long long left_index = 0;
        long long right_index = N - 1;

        countInv(arr, left_index, right_index);

    }

};
