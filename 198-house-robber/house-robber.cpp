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
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i > 1){
                pick += dp[i-2];
            }
            int non_pick = dp[i-1];
            dp[i] = max(pick,non_pick);
        }

        return dp[n-1];
    }
};