// Last updated: 8/20/2026, 9:19:23 PM
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
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head = list1;
        ListNode* temp = list2;
        if(list2->val < list1->val) swap(temp, head);
        head->next = mergeTwoLists(head->next, temp);
        return head;
    }
};