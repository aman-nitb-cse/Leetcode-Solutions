// Last updated: 11/6/2026, 4:38:44 AM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];
        for (int x : nums) {
            mx = max(mx, x);
        }
        int ans = 0;
        for (int x : nums) {
            ans += mx - x;
        }
        return ans;
    }
};