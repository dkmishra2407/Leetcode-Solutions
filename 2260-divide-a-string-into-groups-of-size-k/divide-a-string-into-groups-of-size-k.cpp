class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.length();

        for(int i=0;i<n;){
            int cnt = 1;
            string str = "";
            while(i < n && cnt<=k){
                str += s[i];
                i++;
                cnt++;
            }
            if(str.length() < k){
                for(int j=cnt;j<=k;j++){
                    str += fill;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};