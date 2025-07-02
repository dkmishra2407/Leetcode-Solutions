class Solution {
    stack<TreeNode*> st1, st2;

public:
    void pushall1(TreeNode* root) {
        while (root) {
            st1.push(root);
            root = root->left;
        }
    }

    void pushall2(TreeNode* root) {
        while (root) {
            st2.push(root);
            root = root->right;
        }
    }

    TreeNode* next() {
        TreeNode* temp = st1.top(); st1.pop();
        pushall1(temp->right);
        return temp;
    }

    TreeNode* before() {
        TreeNode* temp = st2.top(); st2.pop();
        pushall2(temp->left);
        return temp;
    }

    bool findTarget(TreeNode* root, int k) {
        pushall1(root);
        pushall2(root);

        TreeNode* low = next();
        TreeNode* high = before();

        while (low != high) {
            int sum = low->val + high->val;
            if (sum == k) return true;
            else if (sum < k) low = next();
            else high = before();
        }

        return false;
    }
};
