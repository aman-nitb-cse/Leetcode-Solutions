// Last updated: 10/24/2026, 9:00:24 PM
1class Solution {
2public:
3    long long countMagicalPairs(string s) {
4        int n = s.size();
5
6        vector<vector<int>> R(n, vector<int>(26));
7        vector<vector<int>> L(n, vector<int>(26));
8        vector<vector<int>> first(n, vector<int> (26, n));
9        vector<vector<int>> last(n, vector<int> (26, -1));
10
11        last[0][s[0] - 'a'] = 0;
12        for(int i = 1; i < n; i++){
13            last[i] = last[i - 1];
14            last[i][s[i] - 'a'] = i;
15        }
16
17        first[n - 1][s[n - 1] - 'a'] = n - 1;
18        for(int i = n - 2; i >= 0; i--){
19            first[i] = first[i + 1];
20            first[i][s[i] - 'a'] = i;
21        }
22
23        for(int i = 0; i < n; i++){
24            vector<int> pos = last[i];
25            ranges::sort(pos, greater<int>());
26
27            for(int m = 0; m < 26; m++){
28                int curr = pos[m];
29                if(curr == -1) break;
30
31                int nxt = (m + 1 < 26) ? pos[m + 1] : -1;
32                L[i][m] = curr - nxt;
33            }
34        }
35
36        for(int i = 0; i < n; i++){
37            vector<int> pos = first[i];
38            ranges::sort(pos);
39
40            for(int m = 0; m < 26; m++){
41                int curr = pos[m];
42                if(curr == n) break;
43
44                int nxt = (m + 1 < 26) ? pos[m + 1] : n;
45                R[i][m] = nxt - curr;
46            }
47        }
48
49        long long ans = 0;
50        for(int i = 0; i < n - 1; i++){
51            for(int d = 0; d < 26; d++){
52                ans += 1LL * L[i][d] * R[i + 1][d];
53            }
54        }
55
56        return ans;
57    }
58};