class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        int prevs = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] - prevs <= k){
                continue;
            }
            else{
                prevs = nums[i];
                cnt++;
            }
        }
        return cnt+1;
    }
};