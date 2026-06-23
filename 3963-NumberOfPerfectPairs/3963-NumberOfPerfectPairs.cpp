// Last updated: 6/24/2026, 3:29:25 AM
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for(int &i : nums) i = abs(i);

        ranges::sort(nums);

        long long cnt = 0;

        for(int i = 0, j = 1; i < nums.size(); i++){
            while(j < nums.size() && nums[j] <= 2 * nums[i]) j++;

            cnt += j - i - 1;
        }

        return cnt;
    }
};