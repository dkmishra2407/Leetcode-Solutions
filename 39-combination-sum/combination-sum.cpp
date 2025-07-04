class Solution {
public:
    vector<vector<int>> ans;

    void f(int n, vector<int>& arr, int k, int sum, int i, vector<int>& path) {
        if(i == n){
            if(sum == k){
                ans.push_back(path);
            }
            return;
        }

        if(sum + arr[i] <= k){
            path.push_back(arr[i]);
            f(n, arr, k, sum + arr[i], i, path);
            path.pop_back();  
        }

        f(n, arr, k, sum, i+1, path);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int> path;
        int n = arr.size();
        f(n, arr, k, 0, 0, path);
        return ans;
    }
};
