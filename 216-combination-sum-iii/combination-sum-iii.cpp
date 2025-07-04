class Solution {
public:
    vector<vector<int>> ans;
    void f(int target, vector<int>& arr, int n, int i, int sum,
           vector<int>& path) {
            if (path.size() > n) return;

        if (path.size() == n && sum == target) {
            ans.push_back(path);
            return;
        }
        if (i > 9 || sum > target) {
            return;
        }

        path.push_back(arr[i]);
        f(target, arr, n, i + 1, sum + arr[i], path);
        path.pop_back();
        f(target, arr, n, i + 1, sum, path);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<int> arr;

        for (int i = 1; i <= 9; i++) {
            arr.push_back(i);
        }
        f(n, arr, k, 0, 0, path);
        return ans;
    }
};