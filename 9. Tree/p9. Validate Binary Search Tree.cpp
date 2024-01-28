// Tree DFS
// https://www.youtube.com/watch?v=9btwHI_84DM&ab_channel=AnujBhaiya

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
    vector<int> v;
    bool found = true;
    bool firstTime = true;
    int prev;
    
    void printTree(TreeNode* root) {
        if (root->left != NULL)
            printTree(root->left);
        
        if (firstTime) {
            prev = root->val;
            firstTime = false;
        } else {
            if (prev >= root->val) {
                found = false;
                prev = root->val;
                return;
            } else
                prev = root->val;
        }
        
        if (root->right != NULL)
            printTree(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        printTree(root);
        if (v.size() == 1)
            return true;
        
        return found;
    }
};
