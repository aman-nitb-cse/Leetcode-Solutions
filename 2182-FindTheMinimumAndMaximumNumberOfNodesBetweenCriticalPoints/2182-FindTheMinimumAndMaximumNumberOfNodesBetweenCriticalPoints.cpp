// Last updated: 6/25/2026, 11:13:22 PM
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        int prev = head->val;
        
        head = head->next;

        int first = -1, index = 0, last = -1;

        while(head){

            if(head->next && (head->val > max(prev, head->next->val) || head->val < min(prev, head->next->val))){

                if(first == -1) first = index;
                else {
                    if(ans[0] == -1 || ans[0] > index - last) ans[0] = index - last;
                    ans[1] = max(ans[1], index - first);
                }

                last = index;
            }

            // inc
            prev = head->val;
            head = head->next;
            index++;
        }

        return ans;
    }
};