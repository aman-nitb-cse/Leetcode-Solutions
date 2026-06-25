// Last updated: 6/25/2026, 11:21:25 PM
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return nullptr;
        if(root->val == val) return root;
        if(val > root->val) return searchBST(root->right, val);
        return searchBST(root->left, val);
    }
};