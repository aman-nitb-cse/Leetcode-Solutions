// Last updated: 7/19/2026, 8:17:12 AM
1class Solution {
2public:
3    int ans = 0;
4    int f(TreeNode* root){
5        if(!root) return -1;
6
7        int maxi = max({f(root->left), f(root->right), root->val});
8
9        ans += (maxi == root->val);
10
11        return maxi;
12    }
13    int countDominantNodes(TreeNode* root) {
14        f(root);
15        return ans;
16    }
17};