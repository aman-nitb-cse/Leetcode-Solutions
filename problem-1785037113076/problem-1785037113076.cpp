// Last updated: 7/26/2026, 9:08:33 AM
1class Solution {
2public:
3    using ll = long long;
4    long long minCost(int m, int n, vector<vector<int>>& p) {
5        vector<vector<vector<ll>>> d(m, vector<vector<ll>> (n, vector<ll> (2, LLONG_MAX)));
6
7        priority_queue<
8            array<ll,4>,
9            vector<array<ll,4>>,
10            greater<array<ll,4>>
11        > pq; // {i, j, action, cost}
12
13        pq.push({1, 0, 0, 1});
14        d[0][0][1] = 1;
15
16        int dir[] = {1, 0, 1};
17
18        while(!pq.empty()){
19            auto [cost, i, j, a] = pq.top(); pq.pop();
20
21            if(d[i][j][a] != cost) continue;
22            if(i == m - 1 && j == n - 1) return cost;
23
24            ll wait = cost + p[i][j];
25
26            if(wait < d[i][j][a ^ 1]){
27                pq.push({wait, i, j, a ^ 1});
28                d[i][j][a ^ 1] = wait;
29            }
30
31
32            // right and down
33            for(int x = 0; x < 2; x++){
34                ll ni = i + dir[x];
35                ll nj = j + dir[x + 1];
36
37                if(ni >= 0 && nj >= 0 && ni < m && nj < n){
38                    ll cost1 = cost + (ni + 1) * (nj + 1); // dont wait
39
40                    if(!a) cost1 += p[i][j]; // not follow parity
41                    
42
43                    if(cost1 < d[ni][nj][a ^ 1]){
44                        pq.push({cost1, ni, nj, a ^ 1});
45                        d[ni][nj][a ^ 1] = cost1;
46                    }
47                }
48            }
49
50            // left and up
51            for(int x = 0; x < 2; x++){
52                ll ni = i - dir[x];
53                ll nj = j - dir[x + 1];
54
55                if(ni >= 0 && nj >= 0 && ni < m && nj < n){
56                    ll cost1 = cost + (ni + 1) * (nj + 1); // dont wait
57
58                    if(a) cost1 += p[i][j]; // not follow parity
59                    
60
61                    if(cost1 < d[ni][nj][a ^ 1]){
62                        pq.push({cost1, ni, nj, a ^ 1});
63                        d[ni][nj][a ^ 1] = cost1;
64                    }
65                }
66            }
67        }
68
69        return -1;
70    }
71};