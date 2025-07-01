/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findrightend(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findrightend(root->right);
    }
    TreeNode* helptree(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* curr = findrightend(root->left);
        curr->right = rightchild;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helptree(root);
        }

        while (curr != NULL) {
            if (curr->val > key) {
                if (curr->left != NULL && curr->left->val == key) {
                    curr->left = helptree(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right != NULL && curr->right->val == key) {
                    curr->right = helptree(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};