// Last updated: 8/20/2026, 9:09:05 PM
class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<int>& nums, int i, int j){
        if(i > j) return 0;

        auto& _dp = dp[i][j];
        if(_dp != -1) return _dp;

        _dp = 0;
        for(int k = i; k <= j; k++){

            int left = 1, right = 1;
            if(i > 0) left = nums[i - 1];
            if(j + 1 < nums.size()) right = nums[j + 1];
            
            _dp = max(
                _dp, 
                left * nums[k] * right + f(nums, i, k - 1) + f(nums, k + 1, j)
            );
        }
        return _dp;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return f(nums, 0, n - 1);
    }
};