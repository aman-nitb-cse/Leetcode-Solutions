// Last updated: 6/25/2026, 11:15:43 PM
class Solution {
public:
    bool flag(vector<int>& nums, int m, int mid){
        int prev = -1e9;
        for(int &i : nums){
            if(i - prev >= mid){
                m--;
                prev = i;
            } 
        }
        return m <= 0;
    }
    int maxDistance(vector<int>& nums, int m) {
        ranges::sort(nums);
        int s = 1;
        int e = nums.back() - nums.front();
        int ans = e;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(flag(nums, m, mid)){
                ans = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ans;
    }
};