// https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        
        ListNode* prev = NULL;
        ListNode* merged_head = NULL;
        bool first_time = true;
        
        while (list1 != NULL && list2 != NULL) {
            if (first_time) {
                if (list1->val <= list2->val) {
                    merged_head = list1;
                    prev = list1;
                    list1 = list1->next;
                } else {
                    merged_head = list2;
                    prev = list2;
                    list2 = list2->next;
                }
                first_time = false;
                continue;
            }
            
            if (list1->val <= list2->val) {
                ListNode* tmp = list1;
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else {
                ListNode* tmp = list2;
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
        }
        
        if (list1 != NULL) {
            prev->next = list1;
        } else {
            prev->next = list2;
        }
        
        return merged_head;
    }
};
