// Last updated: 6/25/2026, 11:14:33 PM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int,int> freq;

        for(int x : nums) freq[x]++;

        int ans = 0;

        for(auto i = freq.begin(); i != freq.end(); i++){
            auto [x, xf] = *i;

            int op = k;
            int cur = xf;

            auto j = i;

            while(j != freq.begin() && op > 0){
                --j;

                auto [y, yf] = *j;

                int diff = x - y;

                int take = min(yf, op / diff);

                if(take == 0) break;

                op -= take * diff;
                cur += take;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};