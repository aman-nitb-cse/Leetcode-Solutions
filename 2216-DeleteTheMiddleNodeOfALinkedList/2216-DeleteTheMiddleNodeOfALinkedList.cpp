// Last updated: 6/25/2026, 11:13:06 PM
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        auto slow = head;
        auto fast = head->next->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};