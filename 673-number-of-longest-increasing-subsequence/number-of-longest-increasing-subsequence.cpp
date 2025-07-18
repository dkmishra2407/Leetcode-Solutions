class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi = 1;
        int maxc = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    cnt[i] = cnt[j];
                }
                else if(arr[i] > arr[j] && 1 + dp[j] == dp[i]){
                    cnt[i] += cnt[j];
                }
            }

            maxi = max(dp[i],maxi);
        } 
        int nos = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == maxi) {
                nos += cnt[i];
            }
        }

    return nos;
    }
};