// Last updated: 6/25/2026, 11:15:04 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = 0, maxsum = 0, ans = 0, pref = 0;
        for(int &i : nums){
            pref += i;
            ans = max(ans, abs(pref - minsum));
            ans = max(ans, abs(pref - maxsum));
            minsum = min(pref, minsum);
            maxsum = max(pref, maxsum);
        }
        return ans;
    }
};