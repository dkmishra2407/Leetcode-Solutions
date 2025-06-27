class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;

        int i = 0;
        int j = 0;

        int n = s.length();
        unordered_set<char>st;
        while(j < n){
            
            while(st.find(s[j]) != st.end() && i<j){
                st.erase(s[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
            st.insert(s[j]);
            j++;
        }
        return maxi;
    }
};