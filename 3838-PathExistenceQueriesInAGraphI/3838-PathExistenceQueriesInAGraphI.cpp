// Last updated: 7/18/2026, 12:22:21 AM
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> reach(n);
        int r = 0;
        for(int i = 0; i < n; i++){
            while(r < n && nums[r] - nums[i] <= maxDiff) r++;

            reach[i] = r - 1;
        }

        for(int i = n - 2; i >= 0; i--){
            reach[i] = reach[reach[i]];
        }

        // for(int &i : reach) cout << i << ' ';

        vector<bool> ans;

        for(auto &q : queries){
            int u = ranges::min(q);
            int v = ranges::max(q);

            // u -> v
            ans.push_back(v <= reach[u]);
        }
        return ans;
    }
};