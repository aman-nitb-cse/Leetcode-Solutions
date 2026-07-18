// Last updated: 7/18/2026, 8:54:07 PM
1class Solution {
2public:
3    using ll = long long;
4    ll dp[5000];
5    int f(string &s, int idx, string &t, vector<vector<string>>& v, vector<int> & cost){
6        if(idx == s.size()) return 0;
7
8        if(dp[idx] != -1) return dp[idx];
9
10        ll skip = INT_MAX;
11
12        if(s[idx] == t[idx]){
13            skip = f(s, idx + 1, t, v, cost);
14        }
15        
16        ll take = INT_MAX;
17
18        for(int i = 0; i < v.size(); i++){
19            bool valid = true;
20
21            ll cnt = 0;
22            int n = v[i][0].size();
23
24            for(int j = 0; j < n && idx + j < s.size(); j++){
25                if((s[idx + j] != v[i][0][j] && v[i][0][j] != '*')){
26                    valid = false;
27                    break;
28                }
29
30                if((t[idx + j] != v[i][1][j])){
31                    valid = false;
32                    break;
33                }
34
35                if(v[i][0][j] == '*') cnt++;
36            }
37
38            if(valid && idx + n <= s.size()){
39                take = min(take, 0LL + cost[i] + cnt + f(s, idx + n, t, v, cost));
40            }
41        }
42
43        return dp[idx] = min(take, skip);
44    }
45    int minCost(string s, string t, vector<vector<string>>& rules, vector<int>& costs) {
46        memset(dp, -1, sizeof(dp));
47        ll ans = f(s, 0, t, rules, costs);
48
49        if(ans >= 1e9) return -1;
50        return ans;
51    }
52};