// Last updated: 11/6/2026, 5:10:04 AM
class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int prev = 0;
        int count = 1;
        int ans = 1;

        for(int i = 1; i < nums.size(); i++){
            int curr = (nums[i] > nums[i-1]) - (nums[i] < nums[i-1]);

            if(curr == 0) count = 1;
            else if(i > 1 && curr == prev) count = 2;
            else count++;

            ans = max(ans, count);
            prev = curr;
        }

        return ans;
    }
};