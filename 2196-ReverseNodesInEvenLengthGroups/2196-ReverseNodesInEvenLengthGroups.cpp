// Last updated: 6/25/2026, 11:13:17 PM
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
    ListNode* reverseEvenLengthGroups(ListNode* head, int k = 1) {
        if(!head or !head->next) return head;

        // count how many nodes are available
        int size = 0;
        ListNode* i;
        for(i = head; i; i = i->next){
            size++;
            if(size == k) break;
        }
        
        // Odd groups
        if(size & 1){
            if(i) i->next = reverseEvenLengthGroups(i->next, k + 1);
            return head;
        }

        // even groups
        ListNode* p = head;
        ListNode* c = p->next;
        ListNode* f = c->next;
        for(int i = 1; i < size; i++){
            c->next = p;
            if(!f or size == i + 1) break;
            p = c;
            c = f;
            f = f->next;
        }

        head->next = reverseEvenLengthGroups(f, k + 1);
        return c;
    }
};