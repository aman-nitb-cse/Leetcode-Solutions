// Last updated: 11/6/2026, 5:09:21 AM
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(root->val < val) return new TreeNode(val, root, NULL);

        root->right = insertIntoMaxTree(root->right, val);

        return root;
    }
};