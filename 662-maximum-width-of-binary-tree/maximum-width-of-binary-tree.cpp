class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        using ULL = unsigned long long;
        queue<pair<TreeNode*, ULL>> q;
        q.push({root, 0});
        int maxi = 0;

        while (!q.empty()) {
            int n = q.size();
            ULL mini = q.front().second;
            ULL first = 0, last = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                ULL idx = q.front().second - mini;
                q.pop();

                if (i == 0) first = idx;
                if (i == n - 1) last = idx;

                if (curr->left) {
                    q.push({curr->left, idx * 2 + 1});
                }
                if (curr->right) {
                    q.push({curr->right, idx * 2 + 2});
                }
            }

            maxi = max(maxi, (int)(last - first + 1));
        }

        return maxi;
    }
};
