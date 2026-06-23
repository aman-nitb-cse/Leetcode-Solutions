// Last updated: 6/24/2026, 3:32:06 AM
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
    int gcd(int x, int y){
        if(x * y == 0) return x + y;
        return gcd(y % x, x);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* x = head;
        ListNode* y = head->next;

        while(y){
            x->next = new ListNode(gcd(x->val, y->val));
            x->next->next = y;
            x = y;
            y = y->next; 
        }
        return head;
    }
};