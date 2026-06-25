// Last updated: 6/25/2026, 11:37:34 PM
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;

        if(root->val < low) return trimBST(root->right, low, high);
        if(root->val > high) return trimBST(root->left, low, high);

        root->right = trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        return root;
    }
};