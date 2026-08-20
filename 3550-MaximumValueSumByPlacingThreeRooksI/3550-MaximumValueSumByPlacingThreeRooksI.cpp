// Last updated: 8/20/2026, 8:39:01 PM
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& b) {
        int m = b.size();
        int n = b[0].size();

        vector<vector<pair<int,int>>> dp(m);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i].push_back({b[i][j], j});
            }
            sort(dp[i].rbegin(), dp[i].rend());
            while(dp[i].size() > 3) dp[i].pop_back();

            // for(auto& [x, y] : dp[i]) cout << x << ' ' << y << ", ";
            // cout << endl;
        }

        long long ans = -3e9;

        for(int i = 0; i < m; i++){

            for(int l = 0; l < i; l++){

                for(int r = i + 1; r < m; r++){

                    for(auto &[x, c1] : dp[i]){

                        for(auto &[y, c2] : dp[l]){

                            for(auto &[z, c3] : dp[r]){

                                // cout << c1 << ' ' << c2 << ' ' << c3 << endl;

                                if(c1 != c2 && c1 != c3 && c2 != c3){

                                    ans = max(ans, 1LL * x + y + z);

                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};