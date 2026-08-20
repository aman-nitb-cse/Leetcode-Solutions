// Last updated: 8/20/2026, 9:20:53 PM
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(l1 == nullptr) {
            if(l2 == nullptr){
                if(carry == 0) return nullptr;
                return new ListNode(carry);
            }
            if(carry == 0) return l2;
            int sum = l2->val + carry;
            carry = sum / 10;
            ListNode* ans = new ListNode(sum % 10);
            ans->next =  addTwoNumbers(nullptr, l2->next, carry);
            return ans;
        }
        if(l2 == nullptr) {
            if(carry == 0) return l1;
            int sum = l1->val + carry;
            carry = sum / 10;
            ListNode* ans = new ListNode(sum % 10);
            ans->next =  addTwoNumbers(nullptr, l1->next, carry);
            return ans;
        }
        int sum = l1->val + l2->val + carry;
        carry = sum / 10;
        ListNode* ans = new ListNode(sum % 10);
        ans->next = addTwoNumbers(l1->next, l2->next, carry);
        return ans;
    }
};