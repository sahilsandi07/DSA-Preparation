

//User function Template for Java



class Solution{
    boolean game(int A, int B){
        // Code Here
        int absDiff = Math.abs(B - A);
        double goldenRatio = (1 + Math.sqrt(5)) / 2;
        double temp = goldenRatio * absDiff;
        return Math.min(A, B) != (int)temp;
    }
    
}