// Last updated: 6/25/2026, 11:12:25 PM
class Triples{
public:
    int sum = 0, count = 0, ans = 0;
};
class Solution {
public:
    Triples solve(TreeNode* root){
        if(!root) return {0, 0};
        Triples left = solve(root->left);
        Triples right = solve(root->right);
        Triples node;
        node.sum = left.sum + right.sum + root->val;
        node.count = left.count + right.count + 1;
        node.ans = left.ans + right.ans + (node.sum / node.count == root->val);
        return node;
    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root).ans;
    }
};