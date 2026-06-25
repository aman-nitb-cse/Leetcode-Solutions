// Last updated: 6/25/2026, 11:20:16 PM
class Solution {
public:
    bool flag(vector<int>& nums, int h, int mid){
        for(int &i : nums){
            h -= (i + mid - 1) / mid;
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int s = max(1LL ,accumulate(nums.begin(), nums.end(), 0LL) / h);
        int e = ranges::max(nums);

        int ans = e;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(flag(nums, h, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};