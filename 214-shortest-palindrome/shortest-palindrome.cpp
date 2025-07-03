class Solution {
public:
    int search(string& pat, string& txt) {
    int n = txt.length();
    int m = pat.length();
    
    // Step 1: Build LPS array
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Step 2: Pattern matching using LPS
    int ans = 0;
    i = 0; // index for txt
    int j = 0; // index for pat
    while(i < n) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }
         else if(i < n && pat[j] != txt[i]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }

        ans = max(ans,i-j);
    }

    return ans;
}
    string shortestPalindrome(string s) {
        string str = s;
        reverse(s.begin(),s.end());
        int ans = search(str,s);
        return s.substr(0,ans)+ str;
    }
};