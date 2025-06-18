class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (m.find(sum - k) != m.end()) {
                ans += m[sum - k];
            }
            m[sum]++;
        }
        return ans;
    }
};