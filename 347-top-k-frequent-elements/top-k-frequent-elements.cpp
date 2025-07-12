struct cmp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push({it.first,it.second});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
        }

        return ans;
    }
};