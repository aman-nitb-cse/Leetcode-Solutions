// Last updated: 8/20/2026, 9:16:24 PM
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
    ListNode* deleteDuplicates(ListNode* head, int prev = -101) {
        if(!head) return nullptr;
        if(!head->next){
            if(head->val == prev) return nullptr;
            return head;
        }
        if(head->val == prev || head->val == head->next->val) return deleteDuplicates(head->next, head->val);
        head->next = deleteDuplicates(head->next, head->val);
        return head;
    }
};