class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        unordered_map<int, int> m;
        set<vector<int>> s; 

        for (auto it : nums) {
            m[it]++;
        }
        if(m.size() == 1){
            auto it = m.begin();
            if(it->first != 0){
                return {};
            }
            if(it->second >= 3){
                return {{it->first,it->first,it->first}};
            }
            else{
                return {};
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                int third = 0 - nums[i] - nums[j];

                if (m.find(third) != m.end()) {
                    if (nums[i] == third) cnt++;
                    if (nums[j] == third) cnt++;

                    if (m[third] >= cnt + 1) {
                        vector<int> triplet = {nums[i], nums[j], third};
                        sort(triplet.begin(), triplet.end()); 
                        s.insert(triplet); 
                    }
                }
            }
        }

        for (auto it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};
