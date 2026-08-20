// Last updated: 8/20/2026, 9:15:31 PM
class Triples{
public:
    bool isBST;
    int min, max;
};

class Solution {
public:
    Triples solve(TreeNode* root){
        if(root->left && root->right){
            Triples left = solve(root->left);
            if(!left.isBST || left.max >= root->val) return {false, 0, 0};
            Triples right = solve(root->right);
            if(!right.isBST || right.min <= root->val) return {false, 0, 0};
            return {true, left.min, right.max};
        }
        else if(root->right){
            Triples right = solve(root->right);
            if(!right.isBST || right.min <= root->val) return {false, 0, 0};
            return {true, root->val, right.max};
        }
        else if(root->left){
            Triples left = solve(root->left);
            if(!left.isBST || left.max >= root->val) return {false, 0, 0};
            return {true, left.min, root->val};
        }
        return {true, root->val, root->val};
    }
    bool isValidBST(TreeNode* root) {
        return solve(root).isBST;
    }
};