// Last updated: 6/25/2026, 11:11:30 PM
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long pref = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){

            pref += nums[i];

            ans = max(ans, (int)((pref + i) / (i + 1)));
        }

        return ans;
    }
};