// Last updated: 6/25/2026, 11:12:47 PM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                count += (nums[i] == nums[j]) and (i * j % k == 0);
            }
        }
        return count;
    }
};