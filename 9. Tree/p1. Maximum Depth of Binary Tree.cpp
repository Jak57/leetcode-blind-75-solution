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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else if (root->left == NULL && root->right == NULL)
            return 1;
        
        int h;
        int ans = 0;
        root->val = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* cur = q.front();
            h = cur->val;
            ans = max(ans, h);
            q.pop();
            
            if (cur->left != NULL)
            {
                cur->left->val = h+1;
                q.push(cur->left);
            }
            
            if (cur->right != NULL)
            {
                cur->right->val = h+1;
                q.push(cur->right);
            }
        }
        return ans;
    }
};
