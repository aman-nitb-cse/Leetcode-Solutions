// Last updated: 6/24/2026, 3:30:36 AM
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
    unordered_set<int> st;
    ListNode* solve(ListNode* root){
        if(!root) return nullptr;
        if(st.find(root->val) != st.end()) return solve(root->next);
        root->next = solve(root->next);
        return root;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        st = unordered_set<int> (nums.begin(), nums.end());
        return solve(head);
    }
};