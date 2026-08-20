// Last updated: 8/20/2026, 9:06:26 PM
class Solution {
public:
    bool flag(vector<int>& nums, int k, int mid){
        int sum = 0;
        for(int &i : nums){
            sum += i;
            if(sum > mid){
                if(--k < 0) return false;
                sum = i;
            }
        }
        return (sum == 0 || k > 0);
    }
    int splitArray(vector<int>& nums, int k) {
        int s = ranges::max(nums);
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(flag(nums, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};