//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool islucky(int n,int k){
        if(n<k){
            return true;
        }
        else{
            if(n%k==0){
                return false;
            }
            else{
                n-=n/k;
                islucky(n,k+1);
            }
        }
    }
    bool isLucky(int n) {
        
        islucky(n,2);
    }
};