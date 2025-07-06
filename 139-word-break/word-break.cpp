class Solution {
public:
    bool f(string& s, int i, unordered_set<string>& st1, vector<string>& vec, int n, vector<int>& dp) {
        if (i == n) return true;

        if (dp[i] != -1) return dp[i];  // Memoization: use previously computed result

        for (int j = i; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if (st1.find(str) != st1.end()) {
                vec.push_back(str);
                if (f(s, j + 1, st1, vec, n, dp)) {
                    return dp[i] = true;
                }
                vec.pop_back();
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& arr) {
        unordered_set<string> st1(arr.begin(), arr.end());

        vector<string> vec;
        vector<int> dp(s.length(), -1);  // -1 = unvisited, 0 = false, 1 = true
        return f(s, 0, st1, vec, s.length(), dp);
    }
};
