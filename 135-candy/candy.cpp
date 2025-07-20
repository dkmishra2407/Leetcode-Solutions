class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> left(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                left[i] = 1 + left[i - 1];
            }
        }
        int prev = 1;
        ans += max(prev, left[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int curr = 1;
            if (arr[i] > arr[i + 1]) {
                curr = 1 + prev;
            }
            ans += max(curr, left[i]);
            prev = curr;
        }

        return ans;
    }
};