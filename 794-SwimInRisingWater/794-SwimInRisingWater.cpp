// Last updated: 8/20/2026, 8:59:32 PM
class Solution {
public:
    int n;
    int dir[5] = {1, 0, -1, 0, 1};

    bool check(int k, vector<vector<int>> g){
        // take only values <= k

        queue<array<int,2>> q;

        q.push({0, 0});
        g[0][0] = ~ g[0][0];
        

        while(!q.empty()){

            auto [i, j] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){

                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni < 0 || nj < 0 || ni >= n || nj >= n || g[ni][nj] < 0 || g[ni][nj] > k) continue;

                g[ni][nj] = ~ g[ni][nj]; // mark visited

                if(ni == n - 1 && nj == n - 1) return true;

                q.push({ni, nj});
            }
        }
        return false;
    }   
    int swimInWater(vector<vector<int>>& g) {
        n = g.size();

        if(n == 1) return g[0][0];
        
        int s = max(g[0][0], g[n - 1][n - 1]), e = n * n - 1;

        while(s < e){
            int mid = (s + e) >> 1;

            if(check(mid, g)) e = mid;
            else s = mid + 1;
        }

        return s;
    }
};