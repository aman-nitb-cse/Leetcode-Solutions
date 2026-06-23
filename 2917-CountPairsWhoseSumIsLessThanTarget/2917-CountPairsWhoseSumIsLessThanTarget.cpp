// Last updated: 6/24/2026, 3:32:05 AM
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                count += (nums[i] + nums[j] < target);
            }
        }
        return count;
    }
};