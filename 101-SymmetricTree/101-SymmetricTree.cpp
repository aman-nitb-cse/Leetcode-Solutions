// Last updated: 8/20/2026, 9:15:29 PM
class Solution {
public:
    bool isEqual(TreeNode* A, TreeNode* B){
        if(!A || !B) return A == B;
        return (A->val == B->val) && isEqual(A->left, B->right) && isEqual(A->right, B->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
    }
};