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
    TreeNode* helptree(vector<int>& preorder, vector<int>& inorder,int instart,int inend,int prestart,int preend,unordered_map<int,int>& m){

        if(instart > inend || prestart > preend){
            return nullptr;
        }
        int value = preorder[prestart];
        TreeNode* temp = new TreeNode(value);

        int inroot = m[value];
        int numleft = inroot - instart;
        temp->left = helptree(preorder,inorder,instart,inroot-1,prestart+1,prestart+numleft,m);
        temp->right= helptree(preorder,inorder,inroot+1,inend,prestart+numleft+1,preend,m);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }

        return helptree(preorder,inorder,0,n-1,0,n-1,m);
    }   

};