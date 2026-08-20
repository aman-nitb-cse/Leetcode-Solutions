// Last updated: 8/20/2026, 8:41:21 PM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> hash;
        map<int,int> F;

        int s = 0, e = -1, ans = 0;

        auto update = [&](int x, int dif){
            int of = hash[x];
            hash[x] += dif;
            int nf = hash[x];


            F[of]--;
            F[nf]++;

            if(F[of] == 0) F.erase(of);
        };

        while(e < n){
            if(F.empty() || F.rbegin()->first <= k){
                // expand
                ans = max(ans, e - s + 1);
                e++;
                if(e < n) update(nums[e], 1);
            }
            else {
                // shrink
                update(nums[s++], -1);
            }
        }

        return ans;
    }
};