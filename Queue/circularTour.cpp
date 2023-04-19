#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
  public:
  
    int tour(petrolPump p[], int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for (int i=0; i<n; i++)
       {
           balance += p[i].petrol - p[i].distance;
           
           if (balance < 0)
           {
               deficit += balance;
               start = i + 1;
               balance = 0;
           }
       }
       
       if (deficit + balance >= 0)
       {
           return start;
       }
       
       else
       {
           return -1;
       }
    }
};

int main()
{
    int n = 4;
    petrolPump p[n] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    Solution s;
    int result = s.tour(p, n);
    
    if (result == -1)
    {
        cout << "It is not possible to complete the journey.";
    }
    
    else
    {
        cout << "Start from petrol pump " << result << " to complete the journey.";
    }
    
    return 0;
}