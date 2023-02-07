

//User function Template for Java

class Solution
{
    //Function to rotate an array by d elements in counter-clockwise direction. 
    static void rotateArr(int arr[], int d, int n)
    {
        // add your code here
        d=d%n;

        ArrayList<Integer> s= new ArrayList<>();

        for(int i=d; i<n; i++){

            s.add(arr[i]);

        }

        for(int i=0; i<d; i++){

            s.add(arr[i]);

        }

        for(int i=0; i<n; i++){

            arr[i]=s.get(i);

        }
    }
}