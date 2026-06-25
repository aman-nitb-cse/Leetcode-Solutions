// Last updated: 6/25/2026, 11:16:39 PM
class Solution {
public:
    int ans = 0; // maximum nodes in zig-zag path
    pair<int,int> dfs(TreeNode* root){ // returns {left, right}
        if(!root) return {0, 0};

        // ask values from child
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // calc ans
        ans = max(
            ans,
            1 + max(left.second, right.first)
        );
        
        // backtrack
        return {1 + left.second, 1 + right.first};
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans - 1; // returns edges = nodes - 1
    }
};