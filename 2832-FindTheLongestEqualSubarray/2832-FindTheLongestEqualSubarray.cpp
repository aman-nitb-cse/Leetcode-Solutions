// Last updated: 6/30/2026, 2:14:00 PM
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int s = 0, e = -1, n = nums.size(), ans = 0;

        map<int, int> F;
        vector<int> freq(n + 1);

        while(e < n){
            int m = e - s + 1;
            if(F.empty() || m - F.rbegin()->first <= k){
                if(!F.empty()) ans = max(ans, F.rbegin()->first);
                if(e + 1 == n) break;
                int& f = freq[nums[++e]];
                if(F.count(f)) F[f]--;
                if(F[f] == 0) F.erase(f);
                F[++f]++;
            }
            else {
                int& f = freq[nums[s++]];
                F[f]--;
                if(F[f] == 0) F.erase(f);
                f--;
                if(f) F[f]++;
            }
        }
        return ans;
    }
};