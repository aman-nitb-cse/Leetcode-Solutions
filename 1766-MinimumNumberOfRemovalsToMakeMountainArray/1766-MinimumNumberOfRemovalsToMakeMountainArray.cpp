// Last updated: 6/25/2026, 11:15:30 PM
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> lis, pref(n), suf(n);

        for(int i = 0; i < n; i++){
            auto it = ranges::lower_bound(lis, nums[i]);

            pref[i] = it - lis.begin() + 1;

            if(it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
        }

        lis.clear();

        for(int i = n - 1; i >= 0; i--){
            auto it = ranges::lower_bound(lis, nums[i]);

            suf[i] = it - lis.begin() + 1;

            if(it == lis.end()) lis.push_back(nums[i]);
            else *it = nums[i];
        }

        int ans = n;

        for(int i = 0; i < n; i++){
            if(pref[i] > 1 && suf[i] > 1) ans = min(ans, n - (pref[i] + suf[i] - 1));
        }

        return ans;
    }
};