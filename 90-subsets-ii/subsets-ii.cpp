class Solution {
public:
    
    set<vector<int>>ans;
    void f(vector<int>&arr,int i,vector<int>&arr1){
        int n = arr.size();

        if(i==n){
            ans.insert(arr1);
            return;
        }
        //take
        arr1.push_back(arr[i]);
        f(arr,i+1,arr1);
        //non take
        arr1.pop_back();
        f(arr,i+1,arr1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1;
        sort(nums.begin(),nums.end());
        f(nums,0,arr1);
        vector<vector<int>>fans;

        for(auto& it:ans){
            fans.push_back(it);
        }
        return fans;
    }
};