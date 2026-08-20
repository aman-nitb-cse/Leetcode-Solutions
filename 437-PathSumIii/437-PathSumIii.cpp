// Last updated: 8/20/2026, 9:05:55 PM
class Solution {
public:
    unordered_map <long long, int> st = {{0, 1}};
    int pathSum(TreeNode* root, int k, long long sum = 0) {
        if(!root) return 0;
        sum += 1LL * root->val;
        st[sum]++;
        long long ans = 1LL * pathSum(root->left, k, sum) + pathSum(root->right, k, sum);
        st[sum]--;
        ans += st[sum - k];
        return ans;
    }
};