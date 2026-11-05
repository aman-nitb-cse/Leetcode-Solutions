// Last updated: 11/6/2026, 4:31:01 AM
class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();

        vector<vector<int>> cnt(n, vector<int>(27));

        int ans = 0;
        
        for(int i = n - 1; i >= 0; i--){
            bitset<26> bit;
            int uq = 0;

            for(int j = i; j < n; j++) {
                if(!bit[s[j] - 'a']) uq++;
                bit.set(s[j] - 'a');
                cnt[i][uq]++;

                if(j + 1 < n) ans += cnt[j + 1][uq];
            }
        }
        return ans;
    }
};