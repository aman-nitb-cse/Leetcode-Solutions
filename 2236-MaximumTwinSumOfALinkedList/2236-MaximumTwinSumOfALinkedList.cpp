// Last updated: 6/25/2026, 11:13:00 PM
class Solution {
public:
    pair<ListNode*,ListNode*> rev(ListNode* head){
        auto temp = new ListNode(head->val);
        if(!head->next) return {temp, temp};
        auto [newHead, newTail] = rev(head->next);
        newTail->next = temp;
        return {newHead, newTail->next};
    }
    int pairSum(ListNode* a) {
        auto b = rev(a).first;
        int ans = 0;

        while(a){
            ans = max(ans, a->val + b->val);
            a = a->next;
            b = b->next;
        }
        return ans;
    }
};