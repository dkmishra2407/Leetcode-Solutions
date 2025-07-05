class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& arr, int target, int index, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            if (i > index && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            path.push_back(arr[i]);
            f(arr, target - arr[i], i + 1, path); 
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); 
        vector<int> path;
        f(arr, target, 0, path);
        return ans;
    }
};
