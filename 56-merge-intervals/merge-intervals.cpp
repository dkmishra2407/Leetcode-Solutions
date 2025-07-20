class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int mini = arr[0][0];
        int maxi = arr[0][1];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i][0] > maxi){
                ans.push_back({mini,maxi});
                mini = arr[i][0];
                maxi = arr[i][1];
            }
            else{
                mini = min(mini,arr[i][0]);
                maxi = max(maxi,arr[i][1]);
            }
        }

        ans.push_back({mini,maxi});
        return ans;
    }
};