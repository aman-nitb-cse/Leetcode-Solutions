// Last updated: 8/20/2026, 9:03:59 PM
class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root, int r){
        if(!root) return;

        if(ans.size() <= r) ans.push_back(root->val);
        else ans[r] = max(ans[r], root->val);

        dfs(root->left, r + 1);
        dfs(root->right, r + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};