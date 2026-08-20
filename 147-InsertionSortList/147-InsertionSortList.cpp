// Last updated: 8/20/2026, 9:13:06 PM
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;

        for(ListNode* i = head->next, *prev_i = head; i;){
            auto next = i->next;
            bool moved = false;

            for(ListNode* j = head, *prev = NULL; j != i; prev = j, j = j->next){
                if(i->val < j->val){
                    i->next = j;
                    if(prev) prev->next = i;
                    else head = i;

                    prev_i->next = next;
                    moved = true;
                    break;
                }
            }

            if(!moved){
                prev_i = i;
            }

            i = next;
        }
        return head;
    }
};