// Last updated: 8/20/2026, 8:48:07 PM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(ranges::max(nums), ranges::min(nums));
    }
};