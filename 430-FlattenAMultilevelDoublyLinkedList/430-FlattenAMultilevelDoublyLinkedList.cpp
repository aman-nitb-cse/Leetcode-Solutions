// Last updated: 11/6/2026, 5:14:03 AM
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