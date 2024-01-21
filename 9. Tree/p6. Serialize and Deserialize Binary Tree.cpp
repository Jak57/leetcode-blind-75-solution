// Tree DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string ser = "";
    
    void serial(TreeNode* root) {
        if (root == NULL) {
            ser += '*';
            return;
        }
        
        ser += (to_string(root->val) + ',');
        serial(root->left);
        serial(root->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return ser;
        serial(root);
        return ser;
    }
    
    TreeNode* decode(string &data) {
        if (data.size() == 0)
            return NULL;
        
        if (data[0] == '*') {
            data = data.substr(1);
            return NULL;
        }
        
        string num = "";
        int i = 0;
        while (data[i] != ',') {
            num += data[i];
            i++;
        }
        
        data = data.substr(i+1);
        TreeNode* cur = new TreeNode(stoi(num));
        cur->left = decode(data);
        cur->right = decode(data);
        return cur;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
