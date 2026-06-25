// Last updated: 6/25/2026, 11:16:50 PM
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root)
            return root;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if(!root->left && !root->right && root->val == target) return nullptr;
        return root;
    }
};