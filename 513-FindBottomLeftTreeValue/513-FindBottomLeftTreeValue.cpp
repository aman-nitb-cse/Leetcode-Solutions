// Last updated: 8/20/2026, 9:04:02 PM
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
    int row = -1, value = -1;
    void dfs(TreeNode* root, int r){
        if(!root) return;

        dfs(root->left, r + 1);

        if(r > row && !root->left && !root->right){
            row = r;
            value = root->val;
        }

        dfs(root->right, r + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return value;
    }
};