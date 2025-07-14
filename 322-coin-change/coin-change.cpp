class Solution {
public:
    int f(vector<int>& coins, int val,int i,vector<vector<int>>&dp){
        int n = coins.size();
        if(val == 0){
            return 0;
        }
        if (i == n) return INT_MAX;
        if(val < 0){
            return INT_MAX;
        }
        if(i == n-1){
            if(val%coins[i] == 0){
                return (val)/coins[i];
            }
            return INT_MAX;
        }
        
        if(dp[i][val] != -1){
            return dp[i][val];
        }

         int take = INT_MAX;
        int res = f(coins, val - coins[i], i,dp);
        if (res != INT_MAX) {
            take = 1 + res;
        }
        int non_take = 0 + f(coins,val,i+1,dp);

        return dp[i][val] = min(take,non_take);
    }
    int coinChange(vector<int>& coins, int val) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(val+1,-1));
        if(val == 0){
            return val;
        }
        int ans = f(coins,val,0,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};