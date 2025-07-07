class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {

        sort(arr.begin(),arr.end());
        int day = arr[0][0];
        int ans = 0;

         priority_queue<int, vector<int>, greater<int>> pq;

        int ind = 0;
        int n = arr.size();

        while(!pq.empty() || ind < n){

            while(ind < n && arr[ind][0] == day){
                pq.push(arr[ind][1]);
                ind++;
            }

            if(!pq.empty()){
                pq.pop();
                ans++;
            }

            day++;

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }

        return ans;
    }
};
