// https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed
// k way merge

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class cmp{
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        int n, i, j;
        n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for (i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        if (pq.size() == 0)
            return NULL;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if (cur->next != NULL) {
                pq.push(cur->next);
            }
            
            prev->next = cur;
            prev = cur;
        }
        return dummy->next;
    }
};
