// Last updated: 6/25/2026, 11:19:44 PM
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e = 0; // even index
        int o = 1; // odd index
        int n = nums.size();

        while (e < n && o < n) {
            if (!(nums[e] & 1)) {
                e += 2; // correct even
            }
            else if (nums[o] & 1) {
                o += 2; // correct odd
            }
            else {
                swap(nums[e], nums[o]); // fix both
            }
        }
        return nums;
    }
};