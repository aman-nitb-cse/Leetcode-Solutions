// Last updated: 7/18/2026, 12:23:04 AM
class Solution {
public:
    using ll = long long;

    long long maxSubarraySum(vector<int>& nums, int k) {
        ll ans = -1e18;

        auto solve = [&](bool multiply) {

            ll pre = 0;        // before operation
            ll mid = -1e18;    // inside operation
            ll post = -1e18;   // after operation

            for(int x : nums){

                ll val = multiply ? 1LL * x * k : x / k;

                ll npre = max(0LL, pre) + x;
                ll nmid = max({0LL, pre, mid}) + val;
                ll npost = max(mid, post) + x;

                ans = max({ans, nmid, npost});

                pre = npre;
                mid = nmid;
                post = npost;
            }
        };

        solve(true);
        solve(false);

        return ans;
    }
};