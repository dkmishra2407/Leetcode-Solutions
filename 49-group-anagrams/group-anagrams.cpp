class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<int>>mp;
        vector<string>curr = strs;
        int n = strs.size();
        for(int i=0;i<n;i++){
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(i);
        }

        for(auto it:mp){
            vector<string>temp;
            for(auto itr:it.second){
                temp.push_back(curr[itr]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};