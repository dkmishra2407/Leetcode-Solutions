class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                ans.push_back(i); 
            }
        }

        if (ans.empty()) {
            return {};
        }

        set<int> s;
        for (int i = 0; i < ans.size(); i++) {
            int index = ans[i];

            int p = 0;
            while (p <= k) {
                if (index + p < n) {
                    s.insert(index + p);
                }
                p++;
            }

            p = 1; 
            while (p <= k) {
                if (index - p >= 0) {
                    s.insert(index - p);
                }
                p++;
            }
        }

        return vector<int>(s.begin(), s.end());
    }
};
