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
        else {
            int lheight = maxDepth(root->left);
            int rheight = maxDepth(root->right);
            return max(lheight, rheight)+1;
        }
    }
    
    void printCurrentLevel(TreeNode* root, int h, vector<int> &tmp) {
        if (root == NULL)
            return;
        if (h == 1) {
            cout<< root->val << " ";
            tmp.push_back(root->val);
        }
        else {
            printCurrentLevel(root->left, h-1, tmp);
            printCurrentLevel(root->right, h-1, tmp);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > v;
        int h = maxDepth(root);
        for (int i = 1; i <= h; i++) {
            vector<int> tmp;
            printCurrentLevel(root, i, tmp);
            v.push_back(tmp);
        }
        return v;
    }
};
