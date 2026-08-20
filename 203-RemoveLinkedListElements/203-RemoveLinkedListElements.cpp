// Last updated: 8/20/2026, 9:11:49 PM
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
    ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* cur = &dummy;

    while(cur->next){
        if(cur->next->val == val){
            cur->next = cur->next->next;  
            // ❌ skipped deleting node
        }
        else {
            cur = cur->next;
        }
    }
    return dummy.next;
}
};