// Last updated: 6/25/2026, 11:17:12 PM
class Solution {
public:
    multiset<int> st;
    void to_vector(TreeNode* root){
        if(!root) return;
        to_vector(root->left);
        st.insert(root->val);
        to_vector(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        to_vector(root1);
        to_vector(root2);
        return vector<int> (st.begin(), st.end());
    }
};