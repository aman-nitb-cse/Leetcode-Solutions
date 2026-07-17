// Last updated: 7/18/2026, 12:21:30 AM
class Solution {
public:
    using ll = long long;
    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        unordered_set<int> c;

        c.insert(2);

        for(int &num : nums){
            for(int d = 1; 1LL * d  * d <= num; d++){
                if(num % d== 0){
                    if(d > 1) c.insert(d);
                    if(num / d > 1) c.insert(num / d);
                }
            }
        }

        ll ans = LLONG_MIN;
        int prev_k = 2;

        int maxVal = ranges::max(nums);

        for(int k : c){
            ll sum = (nums[0] % k) ? -1LL * nums[0] : nums[0];
            ll maxi = sum;

            for(int j = 1; j < n; j++){
                ll val = (nums[j] % k) ? -1LL * nums[j] : nums[j];
                ll nsum = sum + val;


                sum = max(val, nsum);
                maxi = max(maxi, sum);
            }

            if(maxi > ans || (maxi == ans && k < prev_k)){
                ans = maxi;
                prev_k = k;
            }
        }

        ans = ans * prev_k % mod;
        ans = (ans + mod) % mod;

        return ans;
    }
};