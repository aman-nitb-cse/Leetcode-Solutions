// Last updated: 6/24/2026, 3:26:59 AM
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();

        vector<int> evens(n);
        for (int i = 0; i < n; i++) {
            evens[i] = !(nums[i] & 1);
            if (i) evens[i] += evens[i - 1];
        }

        auto evenCount = [&](int l, int r) -> int {
            if (l > r) return 0;
            return evens[r] - (l > 0 ? evens[l - 1] : 0);
        };

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];

            long long s = k, e = k + evenCount(l, r);

            while (s < e) {
                long long mid = (s + e) / 2;
                long long candidate = 2 * mid;

                int ub = (int)(ranges::upper_bound(nums.begin() + l, nums.begin() + r + 1, (int)candidate) - nums.begin()) - 1;
                int removed = evenCount(l, ub);

                long long remaining = mid - removed;

                if (remaining >= k) e = mid;
                else s = mid + 1;
            }

            ans.push_back((int)(2 * s));
        }
        return ans;
    }
};