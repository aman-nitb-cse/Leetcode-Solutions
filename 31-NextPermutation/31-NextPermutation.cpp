// Last updated: 8/20/2026, 9:18:57 PM
class Solution {
public:
    int bs(vector<int>& nums, int target, int s, int e){
        int ans = s++;

        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] <= target) e = mid - 1;
            else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        for(i = n - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int first = bs(nums, nums[i - 1], i, n - 1);
        swap(nums[first], nums[i - 1]);
        sort(nums.begin() + i, nums.end());
    }
};