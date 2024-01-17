// https://www.youtube.com/watch?v=XVuQxVej6y8&ab_channel=NeetCode
// Two pointers or iterators

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k;
        if (head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        for (k = 1; k <= n; k++) {
            fast = fast->next;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; 
        ListNode* prev = dummy;
        
        while (fast != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        prev->next = slow->next;
        return dummy->next;
    }
};
