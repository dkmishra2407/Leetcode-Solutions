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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root){
            return ans;
        }
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;

            m[col][row].insert(curr->val);
            q.pop();

            if(curr->left){
                q.push({curr->left,{row+1,col-1}});
            }

            if(curr->right){
                q.push({curr->right,{row+1,col+1}});
            }
        }

        for(auto it:m){
            vector<int>col;
            for(auto itr:it.second){
                col.insert(col.end(),itr.second.begin(),itr.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};