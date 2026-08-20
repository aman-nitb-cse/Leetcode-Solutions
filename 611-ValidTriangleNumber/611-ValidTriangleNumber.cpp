// Last updated: 8/20/2026, 9:02:20 PM
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int n = nums.size(), cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x = nums[i] - nums[j];

                // count how many elements are > x in [j + 1, n - 1] 
                cnt += lower_bound(nums.begin() + j + 1, nums.end(), x, greater<int>()) - nums.begin() - j - 1;
            }
        }
        return cnt;
    }
};