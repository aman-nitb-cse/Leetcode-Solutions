// Last updated: 6/25/2026, 11:12:50 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ranges::stable_sort(nums,
            [&](auto &a, auto &b){
                return (a <= pivot && b >= pivot);
            }
        );
        return nums;
    }
};