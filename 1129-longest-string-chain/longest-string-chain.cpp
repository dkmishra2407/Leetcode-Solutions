class Solution {
public:
    static bool mycmp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool isPredecessor(string &small, string &large) {
        if (large.size() != small.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;
        while (i < small.size() && j < large.size()) {
            if (small[i] == large[j]) {
                i++;
                j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), mycmp);
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
