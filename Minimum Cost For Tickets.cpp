class Solution {
public:
    set<int>s;
    int dp[100000]={0};
    
    int ut(int i, vector<int>costs)
    {
        if(i>365)
            return 0;
        if(dp[i] != 0)
            return dp[i];
        
        int ans;
        if(s.find(i) != s.end())
        {
            ans=min(ut(i+1,costs)+costs[0],
                min(ut(i+7,costs)+costs[1],
                    ut(i+30,costs)+costs[2]));
        }
        else
            ans=ut(i+1,costs);
        
        dp[i] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        
        for(int i=0;i<n;i++)
            s.insert(days[i]);
        
        return ut(1,costs);
    }
};
