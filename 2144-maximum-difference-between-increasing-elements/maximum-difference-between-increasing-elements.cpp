class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MAX;

        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i == 0){
                arr[i] = min(ans,nums[i]);
            }
            else{
                arr[i] = min(arr[i-1],nums[i]);
            }
        }

        int maxi = INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]-arr[i]);
        }

        if(maxi == 0){
            return -1;
        }
        return maxi;
    }
};