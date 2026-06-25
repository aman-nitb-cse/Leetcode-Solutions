// Last updated: 6/25/2026, 11:16:12 PM
class Solution {
public:
    int solve(TreeNode* root, multiset<int> &st){
        if(!root) return 0;
        st.insert(root->val);
        int ans = (*st.rbegin() <= root->val);
        ans += solve(root->left, st);
        ans += solve(root->right, st);
        st.erase(st.find(root->val));
        return ans;
    }
    int goodNodes(TreeNode* root) {
        multiset<int> st;
        return solve(root, st);
    }
};