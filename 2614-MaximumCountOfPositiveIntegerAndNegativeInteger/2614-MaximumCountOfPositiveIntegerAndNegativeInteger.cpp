// Last updated: 6/25/2026, 11:11:01 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s < e){
            int m = s + (e - s) / 2;
            if(nums[m] >= 0) e = m;
            else if(nums[m] < 0) s = m + 1;
        }
        while(e < n and nums[e] == 0) e++;
        if(nums[s] >= 0) return max(s, n - e);
        return max(s + 1, n - s - 1);
    }
};