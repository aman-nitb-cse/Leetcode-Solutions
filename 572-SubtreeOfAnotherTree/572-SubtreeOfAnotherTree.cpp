// Last updated: 8/20/2026, 9:02:50 PM
class Solution {
public:
    bool isEqual(TreeNode* A, TreeNode* B){
        if(!A && !B) return true;
        if(!A ^ !B) return false;
        return (A->val == B->val) && isEqual(A->left, B->left) && isEqual(A->right, B->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root ^ !subRoot) return false;
        return  isEqual(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};