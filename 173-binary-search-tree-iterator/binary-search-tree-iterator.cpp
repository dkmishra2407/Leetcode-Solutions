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
class BSTIterator {
    private:
       void  pushall(TreeNode* root){
          if(!root){
            return;
          }
         
          while(root != NULL){
            st.push(root);
            root = root->left;
          }

          return;
       }
public:
    stack<TreeNode*>st;
    TreeNode* CURR = NULL;
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode *tmpNode = st.top();
        st.pop();
        pushall(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
};

