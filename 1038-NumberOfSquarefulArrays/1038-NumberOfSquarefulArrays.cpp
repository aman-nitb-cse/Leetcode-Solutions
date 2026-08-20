// Last updated: 8/20/2026, 8:56:32 PM
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;

    // unordered_set<int> root;

    int dp[15][1 << 14];
    int f(vector<int>& nums, int mask, int prev){
        if(mask + 1 == (1 << n)) return 1;

        int& ans = dp[prev + 1][mask];

        if(ans != -1) return ans;

        ans = 0;

        unordered_set<int> taken;

        for(int j = 0; j < n; j++){
            if(taken.count(nums[j])) continue;
            if(((mask >> j) & 1) == 0){
                if(prev == -1) {
                    ans += f(nums, mask ^ (1 << j), j);
                    ans %= mod;
                    taken.insert(nums[j]);
                }
                else {
                    
                    int sq = sqrt(nums[j] + nums[prev]);
                    if(sq * sq == nums[j] + nums[prev]){
                        ans += f(nums, mask ^ (1 << j), j);
                        ans %= mod;
                        taken.insert(nums[j]);
                    }
                }
            }
        }

        return ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        // int maxi = ranges::max(nums);

        // for(int i = 0; i * i <= 2 * maxi; i++) root.insert(i * i);
        return f(nums, 0, -1);
    }
};