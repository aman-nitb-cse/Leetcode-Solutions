// Last updated: 6/24/2026, 3:28:43 AM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};