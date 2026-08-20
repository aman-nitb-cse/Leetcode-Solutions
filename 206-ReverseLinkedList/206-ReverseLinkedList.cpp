// Last updated: 8/20/2026, 9:11:47 PM
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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* temp = head;
        head = reverseList(head->next);
        temp->next->next = temp;
        temp->next = NULL;
        return head;
    }
};