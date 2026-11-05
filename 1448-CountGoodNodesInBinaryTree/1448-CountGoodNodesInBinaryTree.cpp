// Last updated: 11/6/2026, 5:02:52 AM
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