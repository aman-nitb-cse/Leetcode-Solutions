// Last updated: 8/20/2026, 8:39:08 PM
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
            dp[i].resize(min((int)dp[i].size(), 3));
        }

        vector<vector<pair<int,int>>> pref(m);
        pref[0] = dp[0];
        for(int i = 1; i < m; i++){
            vector<pair<int,int>> candidates = pref[i-1];
            for(auto& p : dp[i]) candidates.push_back(p);
            sort(candidates.rbegin(), candidates.rend());
            
            for(auto& p : candidates){
                bool dup = false;
                for(auto& sel : pref[i]){
                    if(sel.second == p.second) { dup = true; break; }
                }
                if(!dup) {
                    pref[i].push_back(p);
                    if(pref[i].size() == 3) break;
                }
            }
        }

        vector<vector<pair<int,int>>> suff(m);
        suff[m-1] = dp[m-1];
        for(int i = m - 2; i >= 0; i--){
            vector<pair<int,int>> candidates = suff[i+1];
            for(auto& p : dp[i]) candidates.push_back(p);
            sort(candidates.rbegin(), candidates.rend());
            
            for(auto& p : candidates){
                bool dup = false;
                for(auto& sel : suff[i]){
                    if(sel.second == p.second) { dup = true; break; }
                }
                if(!dup) {
                    suff[i].push_back(p);
                    if(suff[i].size() == 3) break;
                }
            }
        }

        long long ans = -1e18;

        for(int i = 1; i < m - 1; i++){
            for(auto& [x, c1] : pref[i-1]){
                for(auto& [y, c2] : dp[i]){
                    for(auto& [z, c3] : suff[i+1]){
                        if(c1 != c2 && c1 != c3 && c2 != c3){
                            ans = max(ans, 1LL * x + y + z);
                        }
                    }
                }
            }
        }

        return ans;
    }
};