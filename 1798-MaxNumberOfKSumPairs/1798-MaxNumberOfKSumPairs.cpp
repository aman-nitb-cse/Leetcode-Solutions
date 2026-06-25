// Last updated: 6/25/2026, 11:15:15 PM
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ranges::sort(nums);

        int s = 0, e = nums.size() - 1, count = 0;
        while(s < e){
            int sum = nums[s] + nums[e];

            if(sum > k) e--;
            else if(sum < k) s++;
            else {
                count++;
                s++;
                e--;
            }
        }
        return count;
    }
};