// Last updated: 6/25/2026, 11:21:00 PM
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n; i){
            int l = i - 1, r = i; 
            while(r < n && nums[r] <= right) r++;

            // now nums[r] > right
            for(int j = i; j < r; j++){
                if(nums[j] >= left){
                    cnt += (j - l) * (r - j);
                    l = j;
                }
            }
            i = r + 1;

            // cout << i << ' ' << cnt << ' ';
        }
        return cnt;
    }
};