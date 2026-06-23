// Last updated: 6/24/2026, 3:28:31 AM
#define ll long long

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<ll> even_suf(n);

        auto cost = [&](int i){
            return max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i]);
        };

        for(int i = n - 2 - (n&1); i >= 2; i -= 2){
            even_suf[i] = cost(i);
            if(i + 2 < n - 1) even_suf[i] += even_suf[i + 2];
        }

        ll odd_pref = 0, ans = LLONG_MAX;
        for(int i = 1; i < n - 1; i += 2){
            ans = min(ans, odd_pref + even_suf[i + 1]);

            odd_pref += cost(i);
        }

        ans = min(ans, odd_pref);
        if(n&1) return odd_pref;
        return ans;
    }
};