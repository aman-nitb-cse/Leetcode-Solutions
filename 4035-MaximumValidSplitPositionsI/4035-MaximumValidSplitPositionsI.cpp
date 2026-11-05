// Last updated: 11/6/2026, 4:31:16 AM
class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for(int skip = -1; skip < n; skip++){
            vector<int> a;
            for(int i = 0; i < n; i++){
                if(i != skip) a.push_back(nums[i]);
            }

            int m = a.size();

            vector<int> pref(m), suf(m);
            
            pref[0] = a[0];
            for(int i = 1; i < m; i++){
                pref[i] = gcd(pref[i - 1], a[i]);
            }
            
            suf[m - 1] = a[m - 1];
            for(int i = m - 2; i >= 0; i--){
                suf[i] = gcd(suf[i + 1], a[i]);
            }

            int sc = 0;
            for(int i = 0; i < m - 1; i++){
                if(pref[i] == suf[i + 1]) sc++;
            }
            ans = max(ans, sc);
        }

        return ans;
    }
};