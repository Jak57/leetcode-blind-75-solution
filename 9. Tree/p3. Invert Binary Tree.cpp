// Tree BFS

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            
            TreeNode* left = cur->left;
            TreeNode* right = cur->right;
            
            TreeNode* tmp = left;
            cur->left = right;
            cur->right = tmp;
            
            if (cur->left != NULL)
                q.push(cur->left);
            
            if (cur->right != NULL)
                q.push(cur->right);
        }
        return root;
    }
};
