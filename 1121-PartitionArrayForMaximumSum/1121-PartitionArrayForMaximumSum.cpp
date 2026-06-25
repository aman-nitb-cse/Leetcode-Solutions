// Last updated: 6/25/2026, 11:18:34 PM
class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums, int k, int i = 0){
        if(i == nums.size()) return 0;
        auto& _dp = dp[i];
        if(_dp != -1) return _dp;
        _dp = 0;
        int maxi = 0;
        for(int j = i; j < min(i + k, (int)nums.size()); j++){
            maxi = max(maxi, nums[j]);
            _dp = max(
                _dp,
                (j - i + 1) * maxi + f(nums, k, j + 1)
            );
        }
        return _dp;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        dp.assign(nums.size(), -1);
        return f(nums, k);
    }
};