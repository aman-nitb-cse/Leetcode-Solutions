// Last updated: 8/29/2026, 8:12:34 PM
1class Solution {
2public:
3    int maxValidSplits(vector<int>& nums) {
4        int n = nums.size(), ans = 0;
5
6        for(int skip = -1; skip < n; skip++){
7            vector<int> a;
8            for(int i = 0; i < n; i++){
9                if(i != skip) a.push_back(nums[i]);
10            }
11
12            int m = a.size();
13
14            vector<int> pref(m), suf(m);
15            
16            pref[0] = a[0];
17            for(int i = 1; i < m; i++){
18                pref[i] = gcd(pref[i - 1], a[i]);
19            }
20            
21            suf[m - 1] = a[m - 1];
22            for(int i = m - 2; i >= 0; i--){
23                suf[i] = gcd(suf[i + 1], a[i]);
24            }
25
26            int sc = 0;
27            for(int i = 0; i < m - 1; i++){
28                if(pref[i] == suf[i + 1]) sc++;
29            }
30            ans = max(ans, sc);
31        }
32
33        return ans;
34    }
35};