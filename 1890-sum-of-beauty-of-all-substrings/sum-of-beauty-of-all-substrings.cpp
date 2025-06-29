class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length(); 

        for(int i = 0; i < n; i++) {
            map<char, int> m;

            for(int j = i; j < n; j++) {
                m[s[j]]++;

                int mini = INT_MAX, maxi = INT_MIN;
                for(auto& it : m) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                ans += (maxi - mini);
            }
        }
        return ans;
    }
};
