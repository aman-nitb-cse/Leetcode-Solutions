// Last updated: 8/20/2026, 9:03:30 PM
class Solution {
public:
    int max_of_subtree(TreeNode* root){
        return root->right ?  max_of_subtree(root->right) : root->val;
    }
    int min_of_subtree(TreeNode* root){
        return root->left ?  min_of_subtree(root->left) : root->val;
    }
    int Min(int a, int b, int c){
        return min(a, min(b, c));
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        if(root->left){
            int left_ans = getMinimumDifference(root->left);
            int left_max = max_of_subtree(root->left);
            ans = Min(ans, left_ans, root->val - left_max);
        }
        if(root->right){
            int right_ans = getMinimumDifference(root->right);
            int right_min = min_of_subtree(root->right);
            ans = Min(ans, right_ans, right_min - root->val);
        }
        return ans;
    }
};