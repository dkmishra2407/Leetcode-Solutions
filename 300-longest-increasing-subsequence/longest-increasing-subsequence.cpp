class Solution {
public:
    int f(vector<int>& nums,int n,vector<vector<int>>&dp,int ind,int prev_ind){
        if(ind == n){
            return 0;
        }
        if(dp[ind][prev_ind+1]  != -1){
            return dp[ind][prev_ind+1];
        }
        int len = 0 + f(nums,n,dp,ind+1,prev_ind);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len,1+f(nums,n,dp,ind+1,ind));
        }

        return dp[ind][prev_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return f(nums,n,dp,0,-1);
    }
};