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
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }

        inorder(root->left);
        
        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        if(!root){
            return;
        }
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            swap(first->val,last->val);
        }
        else{
            swap(first->val,middle->val);
        }
    }
};