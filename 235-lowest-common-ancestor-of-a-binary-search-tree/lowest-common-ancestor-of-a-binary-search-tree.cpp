/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        int curr = root->val;

        if(curr > p->val && q->val < curr){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(curr < p->val && q->val > curr){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }

        // if(root == p || root == q){
        //     return root;
        // }

        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // if(!left){
        //     return right;
        // }
        // else if(!right){
        //     return left;
        // }
        // else{
        //     return root;
        // }
    }
};