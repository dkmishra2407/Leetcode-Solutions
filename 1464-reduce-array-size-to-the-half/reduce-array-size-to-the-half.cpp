class Solution {
public:
    static bool myf(pair<int,int>&a,pair<int,int>&b){
        return a.second > b.second;
    }
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
        }
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(),vec.end(),myf);
        int cnt = 0;
        int sum = 0;
        for(auto it:vec){
            sum += it.second;
            cnt++;
            if(sum >= n/2){
                return cnt;
            }
        }

        return -1;
    }
};