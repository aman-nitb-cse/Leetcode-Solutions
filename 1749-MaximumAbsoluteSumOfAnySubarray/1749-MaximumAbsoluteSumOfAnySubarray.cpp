// Last updated: 11/6/2026, 4:59:40 AM
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