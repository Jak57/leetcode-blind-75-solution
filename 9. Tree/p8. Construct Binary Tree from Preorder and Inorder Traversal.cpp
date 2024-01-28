// https://www.youtube.com/watch?v=ihj4IQGZ2zc&t=760s&ab_channel=NeetCode
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
    map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preI, int preJ, int inI, int inJ) {
        int idx, leftVal, rightVal;
        int val = preorder[preI];
        TreeNode* cur = new TreeNode(val);
        
        idx = mp[val];
        leftVal = idx - inI;
        rightVal = inJ - idx;
        
        if (leftVal > 0) {
            cur->left = build(preorder, inorder, preI+1, preI+leftVal, inI, idx-1);
        }
        
        if (rightVal > 0) {
            cur->right = build(preorder, inorder, preI+leftVal+1, preJ, idx+1, inJ);
        }
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i, j, n, val;
        n = preorder.size();
        
        for (i = 0; i < n; i++) {
            val = inorder[i];
            mp[val] = i;
        }
        
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};
