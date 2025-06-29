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
    vector<TreeNode*> vec1, vec2;

    bool f1(TreeNode* root, TreeNode* a) {
        if (!root) return false;

        vec1.push_back(root);
        if (root == a || f1(root->left, a) || f1(root->right, a)) {
            return true;
        }
        vec1.pop_back();
        return false;
    }

    bool f2(TreeNode* root, TreeNode* a) {
        if (!root) return false;

        vec2.push_back(root);
        if (root == a || f2(root->left, a) || f2(root->right, a)) {
            return true;
        }
        vec2.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        f1(root, p);
        f2(root, q);

        int i = 0;
        while (i < vec1.size() && i < vec2.size() && vec1[i] == vec2[i]) {
            i++;
        }

        return vec1[i - 1];
    }
};
