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
    vector<string>ans;

    void f(TreeNode* root,string str){
        if(!root){
            return;
        }

        str += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(str);
            return;
        }
        str += "->";
        f(root->left,str);
        f(root->right,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            return ans;
        }
        f(root,"");
        return ans;
    }
};