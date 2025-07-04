class Solution {
public:
    vector<vector<int>>ans;

    void f(vector<int>& nums,vector<int>& pass,int n,int i){
        if(i == n){
            ans.push_back(pass);
            return;
        }

        pass.push_back(nums[i]);
        f(nums,pass,n,i+1);
        pass.pop_back();
        f(nums,pass,n,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>pass;
        int n = nums.size();
        f(nums,pass,n,0);
        return ans;
    }
};