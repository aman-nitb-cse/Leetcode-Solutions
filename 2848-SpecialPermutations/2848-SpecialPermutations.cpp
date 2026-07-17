// Last updated: 7/18/2026, 12:24:38 AM
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;

    int dp[15][1 << 14];
    int f(vector<int>& nums, int mask, int prev){
        if(mask + 1 == (1 << n)) return 1;

        int& ans = dp[prev + 1][mask];

        if(ans != -1) return ans;

        ans = 0;

        for(int j = 0; j < n; j++){
            if(((mask >> j) & 1) == 0){
                if(prev == -1 || nums[j] % nums[prev] == 0 || nums[prev] % nums[j] == 0) {
                    ans += f(nums, mask ^ (1 << j), j);
                    ans %= mod;
                }
            }
        }

        return ans;
    }
    int specialPerm(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, -1);
    }
};