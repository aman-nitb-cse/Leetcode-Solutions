// Last updated: 8/20/2026, 9:10:38 PM
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
    bool isPalindrome(ListNode* head) {
        vector <int> v;
        for(ListNode* i = head; i; i = i->next) v.push_back(i->val);
        vector <int> temp = v;
        reverse(v.begin(), v.end());
        return v == temp;
    }
};