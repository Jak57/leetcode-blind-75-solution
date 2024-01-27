// Tree BFS, Tree DFS

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
    void serialize(TreeNode* root, string &ser) {
        if (root == NULL) {
            ser += '*';
            return;
        }
        ser = ser + to_string(root->val) + ',';
        serialize(root->left, ser);
        serialize(root->right, ser);
    }
    
    vector<TreeNode*> candidate(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> can;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            if (cur->val == subRoot->val)
                can.push_back(cur);
            
            if (cur->left != NULL)
                q.push(cur->left);
            
            if (cur->right != NULL)
                q.push(cur->right);
        }
        return can;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> can;
        can = candidate(root, subRoot);
        
        string subTree = "";
        string tree = "";
        serialize(subRoot, subTree);
        
        for (int i = 0; i < can.size(); i++) {
            tree = "";
            serialize(can[i], tree);

            if (tree == subTree)
                return true;
        }
        return false;
    }
};
