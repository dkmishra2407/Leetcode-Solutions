class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;

        for(auto it:nums){
            pq.push(it);
        }
        k--;
        while(!pq.empty() && k--){
            pq.pop();
        }

        return pq.top();
    }
};