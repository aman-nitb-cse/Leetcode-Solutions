// Last updated: 8/20/2026, 9:13:22 PM
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set <ListNode*> st;
        while(st.find(head) == st.end()){
            st.insert(head);
            if(!head) return nullptr;
            head = head->next;
        }
        return head;
    }
};