class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        int maj = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == maj) {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt == 0) {
                maj = nums[i + 1];
            }
        }

        cnt = 0;

        for (auto it : nums) {
            if (it == maj) {
                cnt++;
            }
        }

        if (cnt > n / 2) {
            return maj;
        }
        return -1;
    }
};