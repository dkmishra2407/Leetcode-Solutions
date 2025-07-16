class Solution {
public:
    int f(vector<int>& nums,int n,vector<vector<int>>&dp,int i,int buy){
        if(i >= n){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy){
            profit = max(-nums[i] + f(nums,n,dp,i+1,0),f(nums,n,dp,i+1,1));
        }
        else{
            profit = max(nums[i] + f(nums,n,dp,i+2,1),f(nums,n,dp,i+1,0));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return f(prices,n,dp,0,1);
    }
};