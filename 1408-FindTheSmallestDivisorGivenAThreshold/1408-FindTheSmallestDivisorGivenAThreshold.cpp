// Last updated: 6/25/2026, 11:17:18 PM
class Solution {
public:
    bool flag(vector<int>& nums, int t, int mid){
        for(int &i : nums){
            t -= (i + mid - 1) / mid;
        }
        return t >= 0;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int s = 1;
        int e = ranges::max(nums);
        int ans = e;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(flag(nums, t, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};