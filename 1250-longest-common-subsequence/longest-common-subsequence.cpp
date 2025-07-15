class Solution {
public:
    int f(string s1,string s2,int i,int j,int n,int m){
        if(i >= n || j >= m){
            return 0;
        }
        if(s1[i] == s2[j]){
            return 1 + f(s1,s2,i+1,j+1,n,m);
        }
        else{
            return max(f(s1,s2,i,j+1,n,m),f(s1,s2,i+1,j,n,m));
        }
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=1;i <= n;i++){
            for(int j=1;j <= m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};