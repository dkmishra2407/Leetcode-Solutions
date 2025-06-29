class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        int cnt = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (arr[i] + arr[j] <= target) {
                cnt = (cnt + pow2[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }
};