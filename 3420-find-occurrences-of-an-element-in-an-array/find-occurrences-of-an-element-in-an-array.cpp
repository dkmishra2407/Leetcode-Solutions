class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        int n = nums.size();
        vector<int>ans;
        vector<int>m(n+1,0);
        int cnt = 1;
        for(int i=0;i<n;i++){
            auto it = nums[i];
            if(it == x){
                m[cnt] = i;
                cnt++;
            }
        }

        for(auto it:q){
            if(it < cnt){
                ans.push_back(m[it]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};