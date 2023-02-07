

class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    
    bool givdec(int arr[],int start,int end)
    {
        // int n=sizeof(arr)/sizeof(arr[0]);
        for(int i=start+1;i<=end;++i)
        {
            if(arr[i-1]<arr[i])return false;
            
        }
        return true;
    }
    
    
    bool checkdec(int arr[],int big,int small,int n)
    {
        if(arr[0]>arr[n-1])return false;
        
        return givdec(arr,0,small)&&givdec(arr,big,n-1);
    }
    
    
    
    
    
    
     bool givasc(int arr[],int start,int end)
    {
        // int n=sizeof(arr)/sizeof(arr[0]);
        for(int i=start+1;i<=end;++i)
        {
            if(arr[i-1]>arr[i])return false;
            
        }
        return true;
    }
    
    
    bool checkasc(int arr[],int big,int small,int n)
    {
        if(arr[n-1]>arr[0])return false;
        
        return givasc(arr,0,big)&&givasc(arr,small,n-1);
    }
    
    bool checkRotatedAndSorted(int arr[], int num){
        
        int greater=0;
        int min_num=INT_MAX;
        int max_num=INT_MIN ;
        
         int min_num1=INT_MAX;
        int max_num1=INT_MIN ;
        for(int i=0;i<num;++i)
        {
            if(arr[i]>max_num1)
            {max_num1=arr[i];
            max_num=i;
            
            }
        }
        for(int i=0;i<num;++i)
        {
            if(arr[i]<min_num1)
            {min_num1=arr[i];
            min_num=i;
            }
        }
        // cout<<max_num<<" "<<min_num<<" "<<endl;
        //fordescing
        if(min_num==max_num-1)
        {
            return checkdec(arr,max_num,min_num,num);
        }
        //for ascending
        if(max_num==min_num-1)
        {
            return checkasc(arr,max_num,min_num,num);
        }
        // Your code here
        
    }
};