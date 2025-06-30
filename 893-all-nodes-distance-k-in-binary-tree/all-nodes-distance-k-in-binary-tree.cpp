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
    void f(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
                m[temp->left] = temp;
            }
            if(temp->right){
                q.push(temp->right);
                m[temp->right] = temp;
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>vec;
        if(k == 0){
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*>m;
        f(root,m);
        unordered_map<TreeNode*,bool>vis;
        vis[target] = 1;

        queue<TreeNode*>q;

        q.push(target);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            if(cnt++ == k){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(m[curr] && !vis[m[curr]]){
                    vis[m[curr]] = true;
                    q.push(m[curr]);
                }
            }
        }

        while(!q.empty()){
            vec.push_back(q.front()->val);
            q.pop();
        }
        return vec;
    }
};