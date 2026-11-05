// Last updated: 11/6/2026, 4:45:51 AM
class Solution {
public:
    int same(vector<int>& nums, int i, int p){
        if(i == nums.size()) return 0;

        if((nums[i] & 1) != p) return same(nums, i + 1, p);

        return 1 + same(nums, i + 1, p);
    }

    int diff(vector<int>& nums, int i, int p){
        if(i == nums.size()) return 0;

        if((nums[i] & 1) != p) return diff(nums, i + 1, p);

        return 1 + diff(nums, i + 1, !p);
    }

    int maximumLength(vector<int>& nums) {
        return max({
            same(nums, 0, 0),
            same(nums, 0, 1),
            diff(nums, 0, 0),
            diff(nums, 0, 1)
        });
    }
};

// abababab pattern