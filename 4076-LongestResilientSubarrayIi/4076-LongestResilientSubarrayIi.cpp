// Last updated: 11/6/2026, 4:30:57 AM
class Solution {
public:
    using ll = long long;
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(n, 1);

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] % k == nums[i + 1] % k){
                count[i] += count[i + 1];
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ll r = nums[i] % k;
            int size = count[i];

            int curr = 0;

            if(r == 0) curr = size;
            else {
                ll w = k / gcd(r, k);

                curr = (size - 1) / w * w + 1;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};