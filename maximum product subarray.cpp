// subarray=recurssion (we have choice to pick a ele )
// optimal structure (maximum)
// can use dynamic programming

//algo use kadene subsitute
//1.find max,min for each element
//2.find pro
//3.if nums[i]<0 swap(min,max)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
            return 0;
        int pro=nums[0],mx=nums[0],mn=nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(mx,mn);
            mx=max(nums[i],mx*nums[i]);
            mn=min(nums[i],mn*nums[i]);
            
            pro=max(pro,max(mn,mx));
        }
        
        return pro;
    }
};
