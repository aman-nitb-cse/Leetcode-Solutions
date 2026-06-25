// Last updated: 6/25/2026, 11:20:21 PM
class Solution {
public:
    void dfs(TreeNode* root, string &s){
        if(!root) return;
        if(!root->left && !root->right) s += '#' + to_string(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
    }
    bool leafSimilar(TreeNode* a, TreeNode* b) {
        string _a = "", _b = "";
        dfs(a, _a);
        dfs(b, _b);
        return _a == _b;
    }
};