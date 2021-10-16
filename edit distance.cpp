// the question is we have to make s1==s2 by editing elements in minimum operation(changes)
// we have choice to whether to replace an element or not
// and optimal ans is required
// if s1[]==s2[] we dont need any operation so just move for futher searches
// else search the min operation for all the rest subarray
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        
        if(n==0)
            return m;
        if(m==0)
            return n;
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=i+j;// because we have to edit all the elements
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};
