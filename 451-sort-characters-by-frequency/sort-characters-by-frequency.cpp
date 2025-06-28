class Solution {
public:
    static bool mycmp(pair<char,int>&a,pair<char,int>&b){
        if(a.second == b.second){
            return a.first > b.first;
        }

        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>m;

        for(auto it:s){
            m[it]++;
        }

        vector<pair<char,int>>arr(m.begin(),m.end());

        sort(arr.begin(),arr.end(),mycmp);
        string str = "";
        for(auto it:arr){
            for(int i=0;i<it.second;i++){
                str += it.first;
            }
        }

        return str;
    }
};
