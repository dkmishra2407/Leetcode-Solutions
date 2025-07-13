class Solution {
public:
    int f(vector<int>& nums,vector<int>& dp,int i,int n){
        
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int pick = nums[i] + f(nums,dp,i+2,n);
        int non_pick = f(nums,dp,i+1,n);

        return dp[i] = max(pick,non_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return f(nums,dp,0,n);
    }
};