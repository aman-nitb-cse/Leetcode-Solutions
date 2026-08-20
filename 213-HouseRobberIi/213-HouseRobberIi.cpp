// Last updated: 8/20/2026, 9:11:29 PM
class Solution {
public:
    int rob_help(vector<int> nums, int s, int e) {
        int inc = 0, exc = 0;
        while(s < e){
            int temp = exc + nums[s++];
            exc = max(inc, exc);
            inc = temp;
        }
        return max(inc, exc);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return *nums.begin();
        int ans1 = rob_help(nums, 0, nums.size() - 1);
        int ans2 = rob_help(nums, 1, nums.size());
        return max(ans1, ans2);
    }
};