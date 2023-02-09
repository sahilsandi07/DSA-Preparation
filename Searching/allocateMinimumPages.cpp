class Solution 

{

    private:

    bool isPossible(int A[],int N,int M,int mid){

        int studentCount=1;

        int sumOfPages=0;

        for(int i=0;i<N;i++){

            //Assigning pages the student

            if(sumOfPages+A[i]<=mid){

                sumOfPages+=A[i];

            }

            else{

                studentCount++;

                //if the studentcount becomes greater than the total no of students

                //If the Array element is greater than the mid :- so we cannot assign the book to a student

                //so return false

                if(studentCount>M||A[i]>mid)return false;

                sumOfPages=A[i];

            }

        }

        return true;

    }

    public:

    //Function to find minimum number of pages.

    int findPages(int A[], int N, int M) 

    {

        //No of students are more than the no of books

        if(M>N)return -1;

        //search space is between 0 to sum of the array elements

        int start=0;

        int end=0;

        for(int i=0;i<N;i++)end+=A[i];

        int mid=start+(end-start)/2;

        int ans=-1;

        while(start<=end){

            if(isPossible(A,N,M,mid)){

                //store the ans

                ans=mid;

                //as we requried the minimum ans so going into the left-part

                end=mid-1;

            }

            else{

                //the ans does not exists in the left-part

                start=mid+1;

            }

            mid=start+(end-start)/2;

        }

        return ans;

        

    }

};