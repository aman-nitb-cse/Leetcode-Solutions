// Last updated: 11/6/2026, 5:13:28 AM
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