class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;

        string maxi = s.substr(0, 1);
        int maxilen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        for (int i = 0; i < n; i++) {
            string str1 = expand(i, i);     // Odd length palindrome
            string str2 = expand(i, i + 1); // Even length palindrome

            if (str1.length() > maxilen) {
                maxilen = str1.length();
                maxi = str1;
            }
            if (str2.length() > maxilen) {
                maxilen = str2.length();
                maxi = str2;
            }
        }

        return maxi;
    }
};
