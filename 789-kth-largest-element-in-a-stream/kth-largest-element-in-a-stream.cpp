class KthLargest {
public:

    priority_queue<int,vector<int>,greater<int>>pq;
    int deva = 0;
    KthLargest(int k, vector<int>& nums) {
        deva = k;
        int n = nums.size();
        for(int i=0;i<min(n,k);i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }  
    }
    
    int add(int val) {
        if(pq.empty() || pq.size() < deva){
            pq.push(val);
        }
        else if(pq.top() < val){
                pq.pop();
                pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */