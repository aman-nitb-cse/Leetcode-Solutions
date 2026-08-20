// Last updated: 8/20/2026, 9:03:37 PM
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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        for(ListNode* i = head; i; i = i->next) n++;
        ListNode* left = head;
        ListNode* right = head;
        if(k > n/2) k = n - k + 1;
        for(int i = 0; i < n - k; i++){
            if(i < k - 1) left = left->next;
            right = right->next;
        }
        swap(left->val, right->val);
        return head;
    }
};