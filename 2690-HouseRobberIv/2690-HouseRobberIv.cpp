// Last updated: 6/25/2026, 11:10:47 PM
class Solution {
public:
    bool flag(vector<int>& nums, int k, int mid){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= mid) {
                k--;
                i++;
            }
        }
        return k <= 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int s = ranges::min(nums);
        int e = ranges::max(nums);
        int ans = s;

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