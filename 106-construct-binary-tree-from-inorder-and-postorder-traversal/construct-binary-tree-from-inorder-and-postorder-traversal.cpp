class Solution {
public:
    TreeNode* helptree(vector<int>& inorder, vector<int>& postorder,
                       int instart, int inend, int poststart, int postend,
                       unordered_map<int, int>& m) {

        if (instart > inend || poststart > postend) {
            return nullptr;
        }

        int value = postorder[postend]; // root is last element in postorder
        TreeNode* root = new TreeNode(value);

        int inroot = m[value];
        int numleft = inroot - instart;

        root->left = helptree(inorder, postorder, instart, inroot - 1, poststart, poststart + numleft - 1, m);
        root->right = helptree(inorder, postorder, inroot + 1, inend, poststart + numleft, postend - 1, m);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }

        return helptree(inorder, postorder, 0, n - 1, 0, n - 1, m);
    }
};
