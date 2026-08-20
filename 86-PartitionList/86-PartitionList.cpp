// Last updated: 8/20/2026, 9:16:15 PM
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        bool flag = true;
        while(flag){
            flag = false;
            for(auto i = head; i && i->next; i = i->next){
                if(i->val >= x && i->next->val < x){
                    swap(i->val, i->next->val);
                    flag = true;
                }
            }
        }
        return head;
    }
};