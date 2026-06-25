// Last updated: 6/25/2026, 11:12:40 PM
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *nHead = NULL, *nTail = NULL;

        int sum = 0;
        head = head->next;
        while(head){
            if(head->val == 0){

                auto node = new ListNode(sum);
                sum = 0;

                if(!nHead) nHead = nTail = node;
                else {
                    nTail->next = node;
                    nTail = node;
                }
            }
            else sum += head->val;

            head = head->next;
        }

        return nHead;
    }
};