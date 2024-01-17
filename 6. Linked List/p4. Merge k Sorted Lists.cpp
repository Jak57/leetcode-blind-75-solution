// https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed
// https://www.youtube.com/watch?v=kpCesr9VXDA&t=1111s&ab_channel=Techdose
// K-way merge

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
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        int i, n;
        n = lists.size();
        
        if (n == 0)
            return NULL;
        
        for (i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        if (pq.size() == 0) 
            return NULL;
    
        ListNode* merged_head = new ListNode(-1);
        ListNode* prev = merged_head;
        
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if (cur->next != NULL) {
                pq.push(cur->next);
            }
            
            prev->next = cur;
            prev = cur;
        }
        
        return merged_head->next;
    }
};
