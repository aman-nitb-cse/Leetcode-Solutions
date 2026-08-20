// Last updated: 8/20/2026, 8:50:43 PM
class Solution {
public:
    static constexpr int dir[] = {1, 0, -1, 0, 1};

    bool check(vector<vector<int>>& h, int k){
        int m = h.size(), n = h[0].size();

        queue<array<int,2>> q; // {i, j}

        q.push({0, 0});

        // mark visited
        h[0][0] *= -1;

        // BFS Algo

        bool ans = false;

        while(!q.empty() && !ans){

            auto [i, j] = q.front();
            q.pop();

            for(int d = 0; d < 4 && !ans; d++){

                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni < 0 || nj < 0 || ni >= m || nj >= n || h[ni][nj] <= 0 || abs(h[ni][nj] + h[i][j]) > k) continue;

                h[ni][nj] *= -1; // mark visited
                if(ni == m - 1 && nj == n - 1) ans = true;

                q.push({ni, nj});
            }
        }

        // unmark visited
        for(auto &i : h){
            for(int &j : i) j = abs(j);
        }

        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& h) {

        int mini = INT_MAX, maxi = 0;

        for(auto &i : h){
            for(int &j : i){
                mini = min(mini, j);
                maxi = max(maxi, j);
            }
        }

        int s = 0, e = maxi - mini;

        while(s < e){
            int mid = (s + e) >> 1;

            if(check(h, mid)) e = mid;
            else s = mid + 1;
        }

        return e;
    }
};