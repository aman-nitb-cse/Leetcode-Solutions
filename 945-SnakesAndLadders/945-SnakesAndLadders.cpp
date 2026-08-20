// Last updated: 8/20/2026, 8:57:43 PM
class Solution {
public:
    pair<int, int> getPos(int x, int n){
        int r = (x - 1) / n;
        int c = (x - 1) % n;

        int i = n - 1 - r;
        int j = (r & 1) ? n - 1 - c : c;

        return {i, j};
    }

    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();

        vector<bool> visited(n * n + 1);

        queue<array<int, 2>> q; // {number, steps}

        q.push({1, 0});
        visited[1] = true;

        while(!q.empty()){
            auto [x, steps] = q.front();
            q.pop();

            if(x == n * n) return steps;

            for(int k = x + 1; k <= min(x + 6, n * n); k++){

                auto [i, j] = getPos(k, n);

                int nxt = (b[i][j] == -1) ? k : b[i][j];

                if(!visited[nxt]){
                    visited[nxt] = true;
                    q.push({nxt, steps + 1});
                }
            }
        }

        return -1;
    }
};