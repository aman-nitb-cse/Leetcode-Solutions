// Last updated: 8/20/2026, 9:08:37 PM
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // size < 3 : return
        if (!head || !head->next || !head->next->next) return head;

        // Finding Last Odd Node for breaking condition
        ListNode* LastOdd = nullptr;
        for (auto temp = head; temp;) {
            LastOdd = temp;
            if (temp->next) temp = temp->next->next;
            else break;
        }

        int d = 1;
        auto prev = head;
        while (prev != LastOdd) {
            auto curr = prev;
            for (int i = 0; i < d; i++, curr = curr->next);
            auto temp = curr->next;
            curr->next = curr->next->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp;
            d++;
        }
        return head;
    }
};