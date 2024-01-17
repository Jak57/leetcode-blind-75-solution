// Fast and slow pointers, Inorder traversal of linked list

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
    void reorderList(ListNode* head) {
        if (head->next == NULL || head->next->next == NULL)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* other_head = slow->next;
        slow->next = NULL;
        
        ListNode* prev = NULL;
        ListNode* cur = other_head;
        
        while (cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = prev;
        
        while (head1 != NULL && head2 != NULL) {
            ListNode* tmp = head2;
            head2 = head2->next;
            
            ListNode* tmp2 = head1->next;
            head1->next = tmp;
            tmp->next = tmp2;
            head1 = tmp2;
        }
    }
};
