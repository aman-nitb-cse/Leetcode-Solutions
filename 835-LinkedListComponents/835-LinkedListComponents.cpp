// Last updated: 6/25/2026, 11:20:46 PM
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
    int numComponents(ListNode* head, vector<int>& nums) {
        ranges::sort(nums);

        int cnt = 0;
        bool found = false;
        while(head){

            if(ranges::binary_search(nums, head->val)) found = true;
            else {
                cnt += found;
                found = false;
            }

            // inc
            head = head->next;
        }

        cnt += found;

        return cnt;
    }
};