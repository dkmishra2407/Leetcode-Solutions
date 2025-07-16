class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxi = nums[0];
        
        for(int i=1;i<n;i++){
            maxi = min(maxi,nums[i]);
            ans = max(ans,nums[i]-maxi);
        }
        return ans;
    }
}; 