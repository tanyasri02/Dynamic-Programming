#include <bits/stdc++.h>
using namespace std;
int solve(string A, string B) {
    int n=A.size(),m=B.size();
    
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(A[i-1]==B[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
	string A,B;
	cin>>A>>B;
	cout<<solve(A,B)<<endl;
	return 0;
}
