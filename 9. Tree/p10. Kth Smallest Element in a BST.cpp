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
    int cnt = 0;
    int ans;
    void findItem(TreeNode* root, int k) {
        if (root->left != NULL)
            findItem(root->left, k);
        
        cnt += 1;
        if (cnt == k) {
            ans = root->val;
            return;
        }
        
        if (root->right != NULL)
            findItem(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        findItem(root, k);
        return ans;
    }
};
