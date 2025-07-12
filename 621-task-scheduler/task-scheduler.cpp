class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        
        vector<int>freq(26,0);

        for(auto it:tasks){
            freq[it-'A']++;
        }

        for(auto it:freq){
            if(it > 0){
                pq.push(it);
            }
        }
        int ans = 0;
        
        while(!pq.empty()){
            int k = n+1;
            vector<int>temp;
            int cnt = 0;
            while(!pq.empty() && k--){
                if(pq.top()-1 >= 1){
                    temp.push_back(pq.top()-1);
                }
                pq.pop();
                cnt++;
            }            
            
            for(auto it:temp){
                pq.push(it);
            }

            if(pq.empty()){
                ans += cnt;
            }
            else{
                ans += (n+1);
            }
        }

        return ans;
    }
};