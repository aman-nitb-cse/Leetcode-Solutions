// Last updated: 6/25/2026, 11:13:09 PM
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto [mn, mx] = ranges::minmax_element(nums);
        int min_left = mn - nums.begin() + 1;
        int max_left = mx - nums.begin() + 1;
        int min_right = nums.end() - mn;
        int max_right = nums.end() - mx;
        return min({
            min_left + max_right,
            min_right + max_left,
            max(min_left, max_left),
            max(min_right, max_right)
        });
    }
};