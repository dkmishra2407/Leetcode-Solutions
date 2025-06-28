class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if (!root) {
            return vec;
        }

        queue<pair<TreeNode*, int>> q; 
        map<int, int> m;
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();

            m[level] = temp->val;

            if (temp->left) {
                q.push({temp->left, level + 1});
            }

            if (temp->right) {
                q.push({temp->right, level + 1});
            }
        }

        for (auto it : m) {
            vec.push_back(it.second);
        }

        return vec;
    }
};
