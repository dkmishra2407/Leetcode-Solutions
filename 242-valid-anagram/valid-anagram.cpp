class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vec1(26,0),vec2(26,0);

        if(s.length() != t.length()){
            return false;
        }

        int n = s.length();

        for(int i=0;i<n;i++){
            vec1[s[i]-'a']++;
            vec2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(vec1[i] != vec2[i]){
                return false;
            }
        }

        return true;
    }
};