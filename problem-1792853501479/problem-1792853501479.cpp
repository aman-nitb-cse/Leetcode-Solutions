// Last updated: 10/24/2026, 8:21:41 PM
1class Solution {
2public:
3    int countMagicalPairs(string s) {
4        int n = s.size();
5
6        vector<vector<int>> cnt(n, vector<int>(27));
7
8        int ans = 0;
9        
10        for(int i = n - 1; i >= 0; i--){
11            bitset<26> bit;
12            int uq = 0;
13
14            for(int j = i; j < n; j++) {
15                if(!bit[s[j] - 'a']) uq++;
16                bit.set(s[j] - 'a');
17                cnt[i][uq]++;
18
19                if(j + 1 < n) ans += cnt[j + 1][uq];
20            }
21        }
22        return ans;
23    }
24};