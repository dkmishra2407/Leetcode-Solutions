class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash;
        hash.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > hash.back()){
                hash.push_back(nums[i]);
            }
            else{
                int ans = lower_bound(hash.begin(),hash.end(),nums[i]) - hash.begin();
                hash[ans] = nums[i];
            }
        }
        return hash.size();
    }
};