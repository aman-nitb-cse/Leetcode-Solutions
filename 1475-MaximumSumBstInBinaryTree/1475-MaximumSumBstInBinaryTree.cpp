// Last updated: 6/25/2026, 11:16:38 PM
class Solution {
    using arr = array<int, 4>; // min, max, sum, isSubtree
    int ans = 0;
public:
    arr dfs(TreeNode* root){
        if(!root) return {INT_MAX, INT_MIN, 0, 1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        arr curr = {
            min(root->val, left[0]), 
            max(root->val, right[1]), 
            left[2] + right[2] + root->val, 
            left[3] && right[3] && root->val > left[1] && root->val < right[0]
        };

        if(curr[3]) ans = max(ans, curr[2]);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};