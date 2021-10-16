// key word:longest and subsequnce
// har element ke lie check karo piche to koi element esa nhi hai jo uss ele se chota ho 
// arr[n]={10,9,2,5,3,7,101,8}
// dp[n]={ 1,1,1,2,2,3,4,4}
// one because har elem apne me increasing hota hai

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
        }
        for(int i=0;i<n;i++)    
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        
        return *max_element(dp,dp+n);
    }
};
