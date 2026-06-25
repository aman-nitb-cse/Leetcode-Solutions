// Last updated: 6/25/2026, 11:17:42 PM
class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        ranges::sort(nums);

        int count = 0;
        int prev = nums[0];
        vector<bool> freq(nums.size() + 1, false);

        for(int &i : nums){
            if(i == prev) count++;
            else {
                if(freq[count]) return false;
                freq[count] = true;
                prev = i;
                count = 1;
            }
        }
        if(freq[count]) return false;
        return true;
    }
};