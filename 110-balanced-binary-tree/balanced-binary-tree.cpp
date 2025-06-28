/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return 1;
        int left_height = height(root->left);
        int right_height = height(root->right);

        if (abs(left_height - right_height) > 1)
            return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (left && right)
            return 1;
        return 0;
    }
};