// Last updated: 8/20/2026, 9:16:20 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        if(head->val == head->next->val){
            ListNode* temp = head->next;
            head->next = head->next->next;
            delete temp;
            deleteDuplicates(head);
        }
        else {
            head->next = deleteDuplicates(head->next);
        }
        return head;
    }
};