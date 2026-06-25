// Last updated: 6/25/2026, 11:21:17 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(set <int> &st, TreeNode* root){
        if(!root) return;
        st.insert(root->val);
        help(st, root->left);
        help(st, root->right);
    }
    int minDiffInBST(TreeNode* root) {
        set <int> st;
        help(st, root);

        int ans = INT_MAX;
        auto i = st.begin();
        auto j = i; j++;
        while(j != st.end()){
            ans = min(ans, *j - *i);
            i++;
            j++;
        }
        return ans;
    }
};