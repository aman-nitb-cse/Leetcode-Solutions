// Last updated: 6/24/2026, 3:29:40 AM
class Solution {
public:

    int kadane(vector<int>& a){

        int best = INT_MIN;
        int sum = 0;

        for(int x : a){

            sum = max(x, sum + x);

            best = max(best, sum);
        }

        return best;
    }

    int maxScore(vector<vector<int>>& g) {

        int m = g.size(), n = g[0].size();

        int ans = INT_MIN;

        // row wise
        for(int i = 0; i < m; i++){

            ans = max(ans, kadane(g[i]));
        }

        // col wise
        for(int j = 0; j < n; j++){

            vector<int> col;

            for(int i = 0; i < m; i++){
                col.push_back(g[i][j]);
            }

            ans = max(ans, kadane(col));
        }

        // single isolated cells not allowed
        // unless inner cell

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                bool boundary =
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1);

                if(boundary && ans == g[i][j]){

                    ans = INT_MIN;

                    // recompute excluding bad singles

                    // row wise
                    for(int r = 0; r < m; r++){

                        int sum = 0;

                        for(int c = 0; c < n; c++){

                            sum += g[r][c];

                            if(sum == g[r][c] && boundary) continue;

                            ans = max(ans, sum);

                            if(sum < 0) sum = 0;
                        }
                    }

                    // col wise
                    for(int c = 0; c < n; c++){

                        int sum = 0;

                        for(int r = 0; r < m; r++){

                            sum += g[r][c];

                            bool b =
                                (r == 0 || r == m - 1 || c == 0 || c == n - 1);

                            if(sum == g[r][c] && b) continue;

                            ans = max(ans, sum);

                            if(sum < 0) sum = 0;
                        }
                    }

                    return ans;
                }
            }
        }

        return ans;
    }
};