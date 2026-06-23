// Last updated: 6/24/2026, 3:29:07 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < 30; i++){
            int mask = 1 << i;
            vector<int> dp;

            for(int x : nums | views::filter([&](int x){ return x & mask; })){
                auto it = ranges::lower_bound(dp, x);
                if(it == dp.end()) dp.push_back(x);
                else *it = x;
            }

            ans = max(ans, (int)dp.size());
        }

        return ans;
    }
};