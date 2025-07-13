class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){


        if(i == n-1){
            return arr[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = f(i+1,j,n,arr,dp);
        int dia = f(i + 1, j + 1, n, arr, dp);

        return dp[i][j] = arr[i][j] + min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,n,arr,dp);
    }
};