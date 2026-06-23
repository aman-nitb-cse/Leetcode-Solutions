// Last updated: 6/24/2026, 3:31:29 AM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long pref = 0, ans = LLONG_MIN;
        unordered_map<int,long long> mp;

        for(int &x : nums){

            if(mp.count(x - k)) ans = max(ans, pref + x - mp[x - k]);

            if(mp.count(x + k)) ans = max(ans, pref + x - mp[x + k]);

            if(!mp.count(x)) mp[x] = pref;

            else mp[x] = min(mp[x], pref);

            pref += x;
        }

        return (ans == LLONG_MIN) ? 0 : ans;
    }
};