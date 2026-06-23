// Last updated: 6/24/2026, 3:28:54 AM
class Solution {
public:
    using ll = long long;
    vector<vector<int>> G;
    ll dfs(int node, int par, vector<int>& B){

        ll maxi = LLONG_MIN, mini = LLONG_MAX;
        for(int &c : G[node]){
            if(c != par){
                ll x = dfs(c, node, B);
                maxi = max(maxi, x);
                mini = min(mini, x);
            }
        }

        if(maxi != LLONG_MIN) return 2 * maxi - mini + B[node];
        return B[node];
    }
    long long finishTime(int n, vector<vector<int>>& E, vector<int>& B) {
        G.resize(n);

        for(auto &i : E){
            G[i[0]].push_back(i[1]);
            G[i[1]].push_back(i[0]);
        }

        return dfs(0, -1, B);
    }
};