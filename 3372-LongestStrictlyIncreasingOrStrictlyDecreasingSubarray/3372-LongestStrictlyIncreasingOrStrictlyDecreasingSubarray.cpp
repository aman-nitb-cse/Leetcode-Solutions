// Last updated: 6/24/2026, 3:31:05 AM
class Solution {
public:
    int inc(vector<int>& nums){
        int ans = 0;
        int l = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) l++;
            else {
                ans = max(ans, l);
                l = 1;
            }
        }
        ans = max(ans, l);
        return ans;
    }
    int dec(vector<int>& nums){
        int ans = 0;
        int l = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]) l++;
            else {
                ans = max(ans, l);
                l = 1;
            }
        }
        ans = max(ans, l);
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(inc(nums), dec(nums));
    }
};