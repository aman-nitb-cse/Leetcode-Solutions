// Last updated: 6/25/2026, 11:21:36 PM
class Solution {
public:
    Node* flatten(Node* head, Node* next = NULL) {
        if (!head) return next;

        head->next = flatten(head->next, next);
        if (head->next) head->next->prev = head;

        if (head->child) {
            head->next = flatten(head->child, head->next);
            if (head->next) head->next->prev = head;
            head->child = NULL;
        }
        return head;
    }
};