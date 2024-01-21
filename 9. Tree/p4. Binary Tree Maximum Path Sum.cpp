// Tree DFS

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
    int res = -INT_MAX;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int leftVal = max(dfs(root->left), 0);
        int rightVal = max(dfs(root->right), 0);
        res = max(res, leftVal + root->val + rightVal);
        
        return (root->val + max(leftVal, rightVal));
    }
    int maxPathSum(TreeNode* root) {
        int val = dfs(root);
        return res;
    }
};
