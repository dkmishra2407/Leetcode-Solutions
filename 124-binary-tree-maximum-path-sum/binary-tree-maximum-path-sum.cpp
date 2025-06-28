/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;

    int f(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lefti = max(0, f(root->left)); 
        int righti = max(0, f(root->right));

        maxi = max(maxi, root->val + lefti + righti);

        return root->val + max(lefti, righti);
    }

    int maxPathSum(TreeNode* root) {
        f(root);
        return maxi;
    }
};
