class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        if(n == 0) return ans;
        if(n == 1) return nums;
        if(n == 2) {
            if(nums[0] == nums[1]) return {nums[0]};
            return nums;
        }

        int cnt1 = 0, cnt2 = 0;
        int candidate1 = 0, candidate2 = 1; 
        for(int num : nums) {
            if(num == candidate1) {
                cnt1++;
            } else if(num == candidate2) {
                cnt2++;
            } else if(cnt1 == 0) {
                candidate1 = num;
                cnt1 = 1;
            } else if(cnt2 == 0) {
                candidate2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
        }

        if(cnt1 > n / 3) ans.push_back(candidate1);
        if(cnt2 > n / 3) ans.push_back(candidate2);

        return ans;
    }
};
