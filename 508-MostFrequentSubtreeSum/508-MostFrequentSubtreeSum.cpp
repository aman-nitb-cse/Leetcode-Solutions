// Last updated: 8/20/2026, 9:04:01 PM

class Solution {
public:
    unordered_map<int, int> mp;
    
    int dfs(TreeNode* root){
        if(!root) return 0;

        int sum = root->val + dfs(root->left) + dfs(root->right);
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;

        int max_freq = 0;

        for(auto &&[sum, f] : mp){
            if(f == max_freq) ans.push_back(sum);
            else if(f > max_freq) {
                ans = {sum};
                max_freq = f;
            }
        }

        return ans;
    }
};