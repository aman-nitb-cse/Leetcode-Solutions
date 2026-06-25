// Last updated: 6/25/2026, 11:18:46 PM
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        while(head){

            int NGE = 0;

            for(auto i = head->next; i != NULL; i = i->next){
                if(i->val > head->val){
                    NGE = i->val;
                    break;
                }
            }

            ans.push_back(NGE);

            // inc
            head = head->next;
        }

        return ans;
    }
};