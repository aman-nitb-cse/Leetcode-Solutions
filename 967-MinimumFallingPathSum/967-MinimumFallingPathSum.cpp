// Last updated: 6/25/2026, 11:19:38 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int prev = m[i - 1][j];

                if(j) prev = min(prev, m[i - 1][j - 1]);
                if(j + 1 < n) prev = min(prev, m[i - 1][j + 1]);

                m[i][j] += prev;
            }
        }

        return *ranges::min_element(m.back());
    }
};