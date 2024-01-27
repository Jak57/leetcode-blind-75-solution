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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        
        while (!q1.empty() && !q2.empty()) {
            TreeNode* cur1 = q1.front();
            TreeNode* cur2 = q2.front();
            q1.pop();
            q2.pop();
            
            if (cur1->val != cur2->val)
                return false;
            
            if ((cur1->left == NULL && cur2->left != NULL) || (cur1->left != NULL && cur2->left == NULL))
                return false;
            else if ((cur1->right == NULL && cur2->right != NULL) || (cur1->right != NULL && cur2->right == NULL)) 
                return false;
            
            if ((cur1->right != NULL && cur2->right != NULL)) {
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
            
            if ((cur1->left != NULL && cur2->left != NULL)) {
                q1.push(cur1->left);
                q2.push(cur2->left);
            }
        }
        return true;
    }
};

// 02
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
    bool helper(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        else
            return (p->val == q->val && helper(p->left, q->left) && helper(p->right, q->right));
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};
