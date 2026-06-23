// Last updated: 6/24/2026, 3:30:32 AM
class Solution {
public:

    vector<vector<int>> G;
    vector<int> Mx, ans;

    int val(int i){
        return (i & 1) ? 1 : 2;
    }

    void dfs1(int node, int par){

        for(int &c : G[node]){

            if(c == par) continue;

            dfs1(c, node);

            Mx[node] = max(Mx[node], Mx[c] + val(c));
        }
    }

    void dfs2(int node, int par, int up = 0){

        ans[node] = max(Mx[node], up);

        int m = G[node].size();

        vector<int> pref(m), suff(m);

        for(int i = 0; i < m; i++){

            int c = G[node][i];

            pref[i] = suff[i] = (c == par ? -1 : Mx[c] + val(c));

            if(i) pref[i] = max(pref[i], pref[i - 1]);
        }

        for(int i = m - 2; i >= 0; i--){
            suff[i] = max(suff[i], suff[i + 1]);
        }

        for(int i = 0; i < m; i++){

            int c = G[node][i];

            if(c == par) continue;

            int nup = up;

            if(i) nup = max(nup, pref[i - 1]);

            if(i + 1 < m) nup = max(nup, suff[i + 1]);

            dfs2(c, node, nup + val(node));
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        G.resize(n);
        Mx.assign(n, 0);
        ans.assign(n, 0);

        for(auto &ed : edges){
            G[ed[0]].push_back(ed[1]);
            G[ed[1]].push_back(ed[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};