// Last updated: 8/20/2026, 8:36:31 PM
class Solution {
public:
    using ll = long long;
    long long minCost(int m, int n, vector<vector<int>>& p) {
        vector<vector<vector<ll>>> d(m, vector<vector<ll>> (n, vector<ll> (2, LLONG_MAX)));

        priority_queue<
            array<ll,4>,
            vector<array<ll,4>>,
            greater<array<ll,4>>
        > pq; // {i, j, action, cost}

        pq.push({1, 0, 0, 1});
        d[0][0][1] = 1;

        int dir[] = {1, 0, 1};

        while(!pq.empty()){
            auto [cost, i, j, a] = pq.top(); pq.pop();

            if(d[i][j][a] != cost) continue;
            if(i == m - 1 && j == n - 1) return cost;

            ll wait = cost + p[i][j];

            if(wait < d[i][j][a ^ 1]){
                pq.push({wait, i, j, a ^ 1});
                d[i][j][a ^ 1] = wait;
            }


            // right and down
            for(int x = 0; x < 2; x++){
                ll ni = i + dir[x];
                ll nj = j + dir[x + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                    ll cost1 = cost + (ni + 1) * (nj + 1); // dont wait

                    if(!a) cost1 += p[i][j]; // not follow parity
                    

                    if(cost1 < d[ni][nj][a ^ 1]){
                        pq.push({cost1, ni, nj, a ^ 1});
                        d[ni][nj][a ^ 1] = cost1;
                    }
                }
            }

            // left and up
            for(int x = 0; x < 2; x++){
                ll ni = i - dir[x];
                ll nj = j - dir[x + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                    ll cost1 = cost + (ni + 1) * (nj + 1); // dont wait

                    if(a) cost1 += p[i][j]; // not follow parity
                    

                    if(cost1 < d[ni][nj][a ^ 1]){
                        pq.push({cost1, ni, nj, a ^ 1});
                        d[ni][nj][a ^ 1] = cost1;
                    }
                }
            }
        }

        return -1;
    }
};