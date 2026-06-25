// Last updated: 6/25/2026, 11:10:52 PM
class Solution {
public:
    unordered_map<int, long long> sum;

    void solve(TreeNode* root, int l = 1) {
        if (!root)
            return;
        sum[l] += root->val;
        solve(root->left, l + 1);
        solve(root->right, l + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        solve(root);
        multimap<long long, int> M;

        for(auto i = sum.begin(); i != sum.end(); i++){
            M.insert({i->second, i->first});
        }
        int i = 1;
        for(auto it = M.rbegin(); it != M.rend(); i++, it++){
            if(i == k) return it->first;
        }

        return -1;
    }
};