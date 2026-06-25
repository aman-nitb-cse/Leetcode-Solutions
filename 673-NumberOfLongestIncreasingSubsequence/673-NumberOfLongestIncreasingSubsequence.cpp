// Last updated: 6/25/2026, 11:37:30 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dp(n); // dp[i] = {length, count}
        int length = 0, count = 0;
        for(int i = 0; i < n; i++){
            int l = 0, c = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) {
                    if(dp[j].first == l) c += dp[j].second;
                    else if(dp[j].first > l){
                        l = dp[j].first;
                        c = dp[j].second;
                    }
                }
            }
            dp[i] = {l + 1, max(1, c)};
            if(dp[i].first == length) count += dp[i].second;
            else if(dp[i].first > length){
                count = dp[i].second;
                length = dp[i].first;
            }
        }
        return count;
    }
};