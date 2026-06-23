// Last updated: 6/24/2026, 3:29:45 AM
class Solution {
public:
    vector<vector<int>> up, graph;
    vector<int> D, pw;

    void depth(int node, int par){
        up[node][0] = par;

        if(node != 1) D[node] = D[par] + 1;

        for(int nbr : graph[node]){
            if(nbr != par) depth(nbr, node);
        }
    }

    int kthAncestor(int node, int k){

        for(int j = 0; j < 20; j++){

            if((k >> j) & 1) node = up[node][j];
        }

        return node;
    }

    int lca(int u, int v){

        if(D[u] < D[v]) swap(u, v);

        u = kthAncestor(u, D[u] - D[v]);

        if(u == v) return u;

        for(int j = 19; j >= 0; j--){

            if(up[u][j] != up[v][j]){

                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        graph.resize(n + 1);
        D.resize(n + 1);
        pw.resize(n + 1);
        up.assign(n + 1, vector<int>(20));

        for(auto &ed : edges){
            graph[ed[0]].push_back(ed[1]);
            graph[ed[1]].push_back(ed[0]);
        }

        depth(1, 0);

        for(int j = 1; j < 20; j++){

            for(int node = 1; node <= n; node++){

                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }

        pw[0] = 0;

        if(n >= 1) pw[1] = 1;

        for(int i = 2; i <= n; i++){
            pw[i] = (2LL * pw[i - 1]) % 1000000007;
        }

        vector<int> ans;

        for(auto &q : queries){

            int u = q[0];
            int v = q[1];

            int edg = D[u] + D[v] - 2 * D[lca(u, v)];

            ans.push_back(pw[edg]);
        }

        return ans;
    }
};