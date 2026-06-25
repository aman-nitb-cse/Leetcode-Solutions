// Last updated: 6/25/2026, 11:11:13 PM
class Solution {
public:
    int maxi = INT_MIN;
    ListNode* removeNodes(ListNode* root) {
        if(!root) return nullptr;
        ListNode* next = removeNodes(root->next);
        if(root->val < maxi) return next;
        maxi = root->val;
        root->next = next;
        return root;
    }
};