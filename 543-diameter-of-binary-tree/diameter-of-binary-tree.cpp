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
    int res = 0; 

    int height(TreeNode* root){
        if(!root){
            return 0;
        }

        int lefti = height(root->left);
        int righti = height(root->right);

        res = max(res, lefti + righti);

        return 1 + max(lefti, righti);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};
