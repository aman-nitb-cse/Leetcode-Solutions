// Last updated: 8/20/2026, 9:19:19 PM
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
    ListNode* solve(ListNode* head, int k, int index) {
        if (!head or !head->next or index < k)
            return head;

        ListNode* p = head;
        ListNode* c = p->next;
        ListNode* f = c->next;
        for (int i = 1; i < k; i++) {
            c->next = p;

            p = c;
            c = f;
            if (!f)
                break;
            f = f->next;
        }
        head->next = solve(c, k, index - k);
        return p;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;

        ListNode* temp = head;

        while (temp) {
            temp = temp->next;
            size++;
        }

        return solve(head, k, size);
    }
};