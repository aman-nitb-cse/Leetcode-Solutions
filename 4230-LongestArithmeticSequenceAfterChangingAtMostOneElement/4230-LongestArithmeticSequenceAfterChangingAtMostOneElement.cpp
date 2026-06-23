// Last updated: 6/24/2026, 3:27:50 AM
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> pref(n, {0, 0}), suf(n, {0, 0});

        for (int i = 1; i < n; i++) {
            pref[i] = {nums[i] - nums[i-  1], 1};
            if (pref[i - 1].first == pref[i].first) pref[i].second += pref[i - 1].second;
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = {nums[i + 1] - nums[i], 1};
            if (suf[i + 1].first == suf[i].first) suf[i].second += suf[i + 1].second;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto left  = i     ? pref[i - 1] : make_pair(0,0);
            auto right = i + 1 < n ? suf[i + 1]  : make_pair(0,0);

            int curr = 1 + max(left.second, right.second);

            if (i && i + 1 < n) {
                int diff = nums[i+1] - nums[i-1];
                int merge = (left.first == right.first);

                if (left.second >= right.second && diff == 2 * left.first)
                    curr = max(curr, left.second + 2 + (merge ? right.second : 0));

                if (right.second >= left.second && diff == 2 * right.first)
                    curr = max(curr, right.second + 2 + (merge ? left.second : 0));
            }

            ans = max(ans, curr);
        }
        return ans + 1;
    }
};