class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (nums[j] < nums[i]) {
                        cnt++;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};