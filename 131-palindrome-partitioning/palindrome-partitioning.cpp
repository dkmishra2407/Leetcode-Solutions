class Solution {
public:
    vector<vector<string>> ans;
    bool ispali(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void f(string str, int i, vector<string>& vec) {
        if (i == str.length()) {
            ans.push_back(vec);
            return;
        }
        int n = str.length();
        for (int j = 1; j+i <= n; j++) {
            string s = str.substr(i, j);
            if (ispali(s)) {
                vec.push_back(s);
                f(str, i+j, vec);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> vec;
        f(s, 0, vec);
        return ans;
    }
};