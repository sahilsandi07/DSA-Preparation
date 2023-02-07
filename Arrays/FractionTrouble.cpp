class Solution{
	public:
	vector<int>LargestFraction(int n, int d){
	    vector<int> ans;

    double res=0;

    double r= n;

    double k= d;

    double check= r/k;

    int x;

    int a=0;

    int b=0;

    for(int i=10000; i>0; i--)

    {

         x= (((double) i*(double) d)+1)/(double) n;

         if((((double) i/(double) x) > res) && (x<=10000))

         {

             if(((double) i / (double) x)< check)

             {

                 double m=i;

                 double v=x;

                 res=m/v;

                 a=i;

                 b=x;   

             }

         }

         

     }

     ans.push_back(a);

     ans.push_back(b);

     return ans;
	}
};