// Last updated: 6/25/2026, 11:21:19 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e){
            int m = s + (e - s) / 2;
            if(target == nums[m]) return m;
            else if(target > nums[m]) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }
};