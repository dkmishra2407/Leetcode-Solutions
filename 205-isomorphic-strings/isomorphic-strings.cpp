class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> m1, m2;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i], b = t[i];

            if (m1.count(a) && m1[a] != b) return false;
            if (m2.count(b) && m2[b] != a) return false;

            m1[a] = b;
            m2[b] = a;
        }

        return true;
    }
};
