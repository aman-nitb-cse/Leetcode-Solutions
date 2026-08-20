// Last updated: 8/20/2026, 8:36:30 PM
class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& p) {
        vector<vector<vector<ll>>> d(m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));

        priority_queue<
            array<ll, 4>,
            vector<array<ll, 4>>,
            greater<array<ll, 4>>
        > pq; // {cost, i, j, action}

        pq.push({1, 0, 0, 0});
        d[0][0][0] = 1;

        int dir[] = {1, 0, 1};

        while(!pq.empty()) {
            auto [cost, i, j, a] = pq.top(); 
            pq.pop();

            if (d[i][j][a] != cost) continue;
            

            if (i == m - 1 && j == n - 1) return cost;

            if (a == 1) {

                ll nCost = cost + p[i][j]; 
                
                if (nCost < d[i][j][0]) {
                    pq.push({nCost, i, j, 0});
                    d[i][j][0] = nCost;
                }
            } else {

                for(int x = 0; x < 2; x++){
                    ll ni = i + dir[x];
                    ll nj = j + dir[x + 1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                        ll nCost = cost + (ni + 1) * (nj + 1);

                        if (nCost < d[ni][nj][1]) {
                            pq.push({nCost, ni, nj, 1}); 
                            d[ni][nj][1] = nCost;
                        }
                    }
                }
            }
        }

        return -1;
    }
};