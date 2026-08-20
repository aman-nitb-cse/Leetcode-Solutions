// Last updated: 8/20/2026, 8:49:44 PM
class Solution {
public:
    int dp[1 << 14];
    void flip(int &x, int i){
        x ^= (1 << i);
    }
    int f(vector<int>& nums, int mask, int rem = 0){
        if(rem == 0) return 0;

        auto& ans = dp[mask];

        if(ans != -1) return ans;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == -1) continue;
            int nums_i = nums[i];
            nums[i] = -1;
            flip(mask, i);

            for(int j = 0; j < i; j++){
                if(nums[j] == -1) continue;

                int nums_j = nums[j];
                nums[j] = -1;
                flip(mask, j);

                ans = max(ans, rem * gcd(nums_i, nums_j) + f(nums, mask, rem - 1));

                nums[j] = nums_j;
                flip(mask, j);
            }

            nums[i] = nums_i;
            flip(mask, i);
        }

        return ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return f(nums, 0, nums.size() / 2);
    }
};