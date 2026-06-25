// Last updated: 6/25/2026, 11:19:43 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int t) {
        int n = nums.size();
        // prefix sum
        for(int i = 1; i < n; i++) nums[i] += nums[i - 1];

        vector<int> count(n + t + 1); // count[i] = total i prefixes
        count[t] = 1;
        int ans = 0;
        for(int &i : nums) {
            ans += count[i];
            count[i + t]++;
        }
        return ans;
    }
};