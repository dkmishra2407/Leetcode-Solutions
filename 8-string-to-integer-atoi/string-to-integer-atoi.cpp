class Solution {
public:
    int myAtoi(string s) {
        bool isneg = false;
        bool isdigit = false;
        string str = "";
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                isneg = true;
            }
            i++;
        }
        for (; i < s.length(); i++) {
            char it = s[i];
            if (it < '0' || it > '9') {
                break;
            }
            str += it;
        }

        if (str.empty()) {
            return 0;
        }

        int ans = 0;
        for (char it : str) {
            int digit = it - '0';

            if (ans > (INT_MAX - digit) / 10) {
                return isneg ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
        }

        return isneg ? -ans : ans;
    }
};
