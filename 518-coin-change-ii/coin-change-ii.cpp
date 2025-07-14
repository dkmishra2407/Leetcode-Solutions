class Solution {
public:
    int f(int amt, vector<int>& coins,int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(i >= n){
            return 0;
        }
        if(i == n-1){
            return (amt%coins[i] == 0);
        }
        if(dp[i][amt] != -1){
            return dp[i][amt];
        }
        int take = 0;
        if(amt >= coins[i]){
            take = f(amt-coins[i],coins,i,dp);
        }
        int non_take = f(amt,coins,i+1,dp);

        return dp[i][amt] = take + non_take;
    }
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,-1));
        return f(amt,coins,0,dp);
    }
};