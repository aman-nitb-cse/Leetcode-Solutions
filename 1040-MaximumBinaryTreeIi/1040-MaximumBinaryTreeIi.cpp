// Last updated: 6/25/2026, 11:19:00 PM
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        if(root->val < val) return new TreeNode(val, root, NULL);

        root->right = insertIntoMaxTree(root->right, val);

        return root;
    }
};