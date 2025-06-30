class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr) {
                str += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                str += "#,";
            }
        }
        
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            
            // Left
            if (!getline(ss, token, ',')) break;
            if (token == "#") {
                curr->left = nullptr;
            } else {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }
            
            // Right
            if (!getline(ss, token, ',')) break;
            if (token == "#") {
                curr->right = nullptr;
            } else {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }
        
        return root;
    }
};
