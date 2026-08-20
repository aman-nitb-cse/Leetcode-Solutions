// Last updated: 8/20/2026, 9:17:22 PM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        for(auto temp = head; temp; temp = temp->next, n++);
        if(n == 0 || k % n == 0) return head;
        k %= n;
        auto temp = head;
        for(int i = 0; i < n - k - 1; i++, temp = temp->next);
        auto _head = temp->next;
        temp->next = nullptr;
        temp = _head;
        while(temp->next) temp = temp->next;
        temp->next = head;
        return _head;
    }
};