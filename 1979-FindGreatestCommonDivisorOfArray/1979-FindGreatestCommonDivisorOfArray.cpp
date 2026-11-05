// Last updated: 11/6/2026, 4:56:21 AM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(ranges::max(nums), ranges::min(nums));
    }
};