class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        vector<pair<int, int>> pos(100001); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        for (int k = 0; k < arr.size(); k++) {
            int val = arr[k];
            int i = pos[val].first;
            int j = pos[val].second;

            row[i]++;
            col[j]++;

            if (row[i] == m || col[j] == n) {
                return k;
            }
        }

        return -1;
    }
};
