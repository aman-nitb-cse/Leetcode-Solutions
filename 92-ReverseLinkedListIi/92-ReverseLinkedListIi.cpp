// Last updated: 8/20/2026, 9:15:47 PM
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* s = head;
        ListNode* e = head;
        for(int i = 1; i < right; i++){
            if(i < left) s = s->next;
            e = e->next;
        }

        ListNode* p = s;
        ListNode* c = p->next;
        ListNode* f = c->next;
        while(true){
            c->next = p;
            if(c == e) break;
            p = c;
            c = f;
            f = f->next;
        }
        s->next = f;
        if(1 == left) return c;
        ListNode* temp = head;
        while(temp->next != s) temp = temp->next;
        temp->next = c;
        return head;
    }
};