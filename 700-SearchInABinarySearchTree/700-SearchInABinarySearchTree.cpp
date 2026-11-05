// Last updated: 11/6/2026, 5:13:42 AM
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return nullptr;
        if(root->val == val) return root;
        if(val > root->val) return searchBST(root->right, val);
        return searchBST(root->left, val);
    }
};