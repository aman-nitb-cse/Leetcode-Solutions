// Last updated: 8/20/2026, 9:01:33 PM
class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(st.find(k - root->val) != st.end()) return true;
        st.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};