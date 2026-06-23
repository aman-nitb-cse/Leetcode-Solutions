// Last updated: 6/24/2026, 3:26:55 AM
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n), suf(n), ans;
        pref[1] = 1;
        for(int i = 2; i < n; i++){
            if(abs(nums[i - 1] - nums[i]) < abs(nums[i - 1] - nums[i - 2])) pref[i]++;
            else pref[i] += abs(nums[i - 1] - nums[i]);

            pref[i] += pref[i - 1];
        }
        suf[n - 2] = 1;
        for(int i = n - 3; i >= 0; i--){
            if(abs(nums[i + 1] - nums[i]) <= abs(nums[i + 1] - nums[i + 2])) suf[i]++;
            else suf[i] += abs(nums[i + 1] - nums[i]);

            suf[i] += suf[i + 1];
        }

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int res = 0;
            if(l < r) res = pref[r] - pref[l];
            else res = suf[l] - suf[r];

            ans.push_back(abs(res));
        }
        // for(auto &i : pref) cout << i << ' ';
        // cout << endl;
        // for(auto &i : suf) cout << i << ' ';
        return ans;
    }
};