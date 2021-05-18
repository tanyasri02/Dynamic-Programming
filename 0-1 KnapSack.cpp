#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define test() int t;cin>>t;while(t--)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      int dp[n+1][W+1];
      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=W;j++)
          {
              if(i==0||j==0)
              dp[i][j]=0;
              
              else if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
              else
              dp[i][j]=max(val[i-1]+
                            dp[i-1][j-wt[i-1]],
                            dp[i-1][j]);
            //  else
            //   dp[i][j]=dp[i-1][j];
          }
      }
      return dp[n][W];
    }
};
int main() {
   test()
   {
       int n,W;
       cin>>n>>W;
       
       int wt[n],val[n];
       
       for(int i=0;i<n;i++)
       cin>>val[i];
       
       for(int i=0;i<n;i++)
       cin>>wt[i];
       
       Solution ob;
       
       cout<<ob.knapSack(W,wt,val,n)<<endl;
   }
   return 0;
}