// Last updated: 6/25/2026, 11:18:53 PM
class Solution {
public:
    bool flag(vector<int>& nums, int days, int mid){
        int sum = 0;
        for(int &i : nums){
            sum += i;
            if(sum > mid){
                sum = i;
                days--;
            }
        }
        if(sum) days--;
        return days >= 0;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int s = ranges::max(nums);
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans = e;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(flag(nums, days, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};