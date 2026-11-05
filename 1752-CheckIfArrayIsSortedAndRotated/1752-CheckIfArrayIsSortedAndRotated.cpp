// Last updated: 11/6/2026, 4:59:24 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int drops = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                drops++;
            }
        }

        return drops <= 1;
    }
};