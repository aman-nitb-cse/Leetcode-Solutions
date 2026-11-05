// Last updated: 11/6/2026, 5:10:21 AM
class Solution {
public:
    vector<int> dfs(TreeNode* root){ // {hasCam, covered, notCovered}
        if(!root) return {(int)1e9, 0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        return {
            1 + ranges::min(left) + ranges::min(right), 
            min(
                left[0] + min(right[0], right[1]),
                right[0] + min(left[0], left[1])
            ), 
            left[1] + right[1]
        };
    }

    int minCameraCover(TreeNode* root) {
        auto res = dfs(root);
        return min(res[0], res[1]);
    }
};