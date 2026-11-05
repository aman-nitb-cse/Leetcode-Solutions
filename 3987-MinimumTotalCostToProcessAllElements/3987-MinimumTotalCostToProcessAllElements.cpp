// Last updated: 11/6/2026, 4:31:52 AM
#define ll long long
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        const int mod = 1e9 + 7;
        ll cnt = 0, cur = k;

        for(int x : nums){
            if(cur < x){
                int need = x - cur;
                int m = (need + k - 1) / k;
                cnt += m;
                cur += m * k;
            }
            cur -= x;
        }

        cnt %= mod;

        return cnt * (cnt + 1) / 2 % mod;
    }
};