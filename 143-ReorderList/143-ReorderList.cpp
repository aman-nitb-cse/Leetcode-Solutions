// Last updated: 8/20/2026, 9:13:19 PM
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
    ListNode* reverseList(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* p = head;
        ListNode* c = p->next;
        ListNode* f = c->next;
        while(true){
            c->next = p;

            if(!f) break;
            p = c;
            c = f;
            f = f->next;
        }
        head->next = NULL;
        return c;
    }

    ListNode* splitMid(ListNode* head){
        if(!head or !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next){ 
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }

    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        ListNode* i = reverseList(splitMid(head));
        while(i){
            ListNode* temp = i;
            i = i->next;
            temp->next = head->next;
            head->next = temp;
            head = head->next->next;
        }
    }
};