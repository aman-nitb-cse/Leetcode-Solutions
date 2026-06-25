// Last updated: 6/25/2026, 11:11:27 PM
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        vector<pair<int,int>> v(nums.size());
        for(int i = 0; i < nums.size(); i++) v[i] = {nums[i], cost[i]};

        ranges::sort(v);

        long long tot = 0;
        for(auto &[x,c] : v) tot += c;

        long long pref = 0;
        int med = 0;

        for(auto &[x,c] : v){
            pref += c;
            if(pref * 2 >= tot){
                med = x;
                break;
            }
        }

        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
            ans += 1LL * abs(nums[i] - med) * cost[i];

        return ans;
    }
};