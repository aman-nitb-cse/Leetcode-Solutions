// Last updated: 8/20/2026, 8:55:05 PM
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        const int mod = 1e9 + 7;

        vector<vector<int>> sum(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n));

        sum[0][0] = 0;
        ways[0][0] = 1;

        int dir[] = {0, 1, 1, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(sum[i][j] == -1) continue;

                for(int d = 0; d < 3; d++){

                    int ni = i + dir[d];
                    int nj = j + dir[d + 1];

                    if(ni >= n || nj >= n || b[ni][nj] == 'X') continue;

                    int curr = sum[i][j];
                    if(b[ni][nj] >= '0' && b[ni][nj] <= '9') curr += b[ni][nj] - '0';

                    if(curr > sum[ni][nj]){
                        sum[ni][nj] = curr;
                        ways[ni][nj] = ways[i][j];
                    }
                    else if(curr == sum[ni][nj]){
                        ways[ni][nj] += ways[i][j];
                        ways[ni][nj] %= mod;
                    }
                }
            }
        }

        if(sum[n - 1][n - 1] == -1) return {0, 0};

        return {sum[n - 1][n - 1], ways[n - 1][n - 1]};
    }
};