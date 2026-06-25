// Last updated: 6/25/2026, 11:10:45 PM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // find index for which pair sum <= upper
            int l = -1, u = -1;
            for (int s = i + 1, e = n - 1; s <= e;) {
                int mid = s + (e - s) / 2;
                int sum = nums[i] + nums[mid];
                if (sum <= upper) {
                    u = mid;
                    s = mid + 1;
                } else
                    e = mid - 1;
            }

            // find index for which pair sum >= lower
            for (int s = i + 1, e = n - 1; s <= e;) {
                int mid = s + (e - s) / 2;
                int sum = nums[i] + nums[mid];
                if (sum >= lower) {
                    l = mid;
                    e = mid - 1;
                } else
                    s = mid + 1;
            }
            if (u != -1 and l != -1)
                count += u - l + 1;
        }
        return count;
    }
};