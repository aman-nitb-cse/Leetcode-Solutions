// Last updated: 6/24/2026, 3:32:23 AM
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();

        priority_queue<array<int,3>> pq;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pq.push({mat[i][j], i, j});
            }
        }

        vector<int> row(m), col(n);

        int ans = 0;

        while(!pq.empty()){

            int x = pq.top()[0];

            vector<array<int,3>> curr;

            while(!pq.empty() && pq.top()[0] == x){
                curr.push_back(pq.top());
                pq.pop();
            }

            vector<int> dp(curr.size());

            for(int k = 0; k < curr.size(); k++){

                auto [x, i, j] = curr[k];

                dp[k] = 1 + max(row[i], col[j]);

                ans = max(ans, dp[k]);
            }

            for(int k = 0; k < curr.size(); k++){

                auto [x, i, j] = curr[k];

                row[i] = max(row[i], dp[k]);
                col[j] = max(col[j], dp[k]);
            }
        }

        return ans;
    }
};