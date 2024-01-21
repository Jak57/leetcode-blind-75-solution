1.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int i;
        vector<vector<int>> ans(2005);
        vector<vector<int>> tmp;
        
        if (root == NULL)
            return tmp;
        
        queue<TreeNode*> q;
        ans[0] = {root->val};
        root->val = 0;
        q.push(root);
        
        int h;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            h = cur->val;
            
            if (cur->left != NULL) {
                ans[h+1].push_back(cur->left->val);
                cur->left->val = h+1;
                q.push(cur->left);
            }
            
            if (cur->right != NULL) {
                ans[h+1].push_back(cur->right->val);
                cur->right->val = h+1;
                q.push(cur->right);
            }
        }
        
        for (i = 0; i < ans.size(); i++) {
            if (ans[i].size() == 0)
                break;
            tmp.push_back(ans[i]);
        }
        
        return tmp;
    }
};

2.
// Tree BFS (Slightly memory efficient)
// https://www.youtube.com/watch?v=6ZnyEApgFYg&ab_channel=NeetCode
    
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int i;
        vector<vector<int>> tmp;
        if (root == NULL)
            return tmp;
        
        queue<TreeNode*> q;
        q.push(root);
        int size;

        while (!q.empty()) {
            vector<int> t;
            size = q.size();
            
            for (i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                t.push_back(cur->val);
                
                if (cur->left != NULL)
                    q.push(cur->left);
                
                if (cur->right != NULL)
                    q.push(cur->right);
            }
            tmp.push_back(t);
        }
        return tmp;
    }
};
