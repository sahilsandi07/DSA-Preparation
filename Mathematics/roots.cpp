
class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
         long long d=(b*b)-4*a*c;

        vector<int>vec1;

        if(d<0)

        {

            vec1.push_back(-1);

        }

        else

        {

            int x1=floor((-b+sqrt(d))/(2*a));

            int x2=floor((-b-sqrt(d))/(2*a));

            vec1.push_back(x1);

            vec1.push_back(x2);

        }

        sort(vec1.begin(),vec1.end(),greater<int>());

        return vec1;

    }
};