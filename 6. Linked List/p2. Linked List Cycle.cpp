// https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed
// Fast and slow pointers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (fast->next == NULL || fast->next->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
               break;
        }
        return true;
    }
};
