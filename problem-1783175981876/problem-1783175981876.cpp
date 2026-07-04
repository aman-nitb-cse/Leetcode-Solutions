// Last updated: 7/4/2026, 8:09:41 PM
1class Solution {
2public:
3    bool isMiddleElementUnique(vector<int>& nums) {
4        int n = nums.size();
5        int mid = n / 2;
6
7        for(int i = 0; i < n; i++){
8            if(nums[i] == nums[mid] && i != mid) return false;
9        }
10
11        return true;
12    }
13};