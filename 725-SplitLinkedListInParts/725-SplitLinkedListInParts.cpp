// Last updated: 6/25/2026, 11:36:54 PM
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for(auto temp = head; temp; temp = temp->next, n++);
        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans;
        while(ans.size() < k){
            if(!head) ans.push_back(nullptr);
            int s = size;
            if(extra){
                s++;
                extra--;
            }

            auto temp = head;
            for(int i = 0; i < s - 1; i++, temp = temp->next);
            if(!temp) continue;
            ans.push_back(head);
            head = temp->next;
            temp->next = nullptr;
        }
        return ans;
    }
};