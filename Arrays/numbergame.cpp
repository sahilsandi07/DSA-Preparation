


class Solution {
   static Long numGame(Long n) {
       int mid=1000000007;
       
       if(n==1){
           return n;
       }
       long ans=1;
       for(int i=1;i<=n;i++){
           ans=((ans*i)/gcd(ans,i))%mid;
       }
       return ans;
   }
   static long gcd(long ans,long i){
       
       if(i==0){
           return ans;

       }
       return (gcd(i,(ans%i)));
   }
}