// Last updated: 8/20/2026, 9:07:46 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        ranges::sort(nums);

        vector<int> dp(n,1), prev(n,-1);

        int maxLen = 1, last = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                last = i;
            }
        }

        vector<int> ans;
        while(last != -1){
            ans.push_back(nums[last]);
            last = prev[last];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};