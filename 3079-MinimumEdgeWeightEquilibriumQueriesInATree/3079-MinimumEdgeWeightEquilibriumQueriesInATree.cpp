// Last updated: 6/24/2026, 3:31:54 AM
class Solution {
public:
    vector<vector<int>> jump, freq;
    vector<vector<array<int,2>>> graph;
    vector<int> D;

    void dfs(int node, int par){

        for(auto &&[c, w] : graph[node]){
            if(c ^ par) {

                jump[c][0] = node;
                freq[c] = freq[node];
                D[c] = 1 + D[node];

                // add the weigth into freq
                freq[c][w - 1]++;

                dfs(c, node);
            }
        }

    }

    int kthAnc(int u, int k){

        for(int i = 0; i < 20; i++){

            if((k >> i) & 1) u = jump[u][i];

        }

        return u;
    }
    int getLCA(int u, int v){

        if(D[u] < D[v]) swap(u, v);

        // D[u] >= D[v]

        u = kthAnc(u, D[u] - D[v]);

        if(u == v) return u;

        for(int i = 19; i >= 0; i--){

            if(jump[u][i] != jump[v][i]){
                u = jump[u][i];
                v = jump[v][i];
            }

        }

        return jump[u][0];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {

        graph.resize(n);
        D.resize(n);
        jump.resize(n, vector<int> (20, -1));
        freq.assign(n, vector<int> (26));

        for(auto &ed : edges){

            graph[ed[0]].push_back({ed[1], ed[2]});
            graph[ed[1]].push_back({ed[0], ed[2]});

        }

        dfs(0, 0);

        for(int i = 1; i < 20; i++){
            for(int node = 0; node < n; node++) {
                if(jump[node][i - 1] != -1) jump[node][i] = jump[jump[node][i - 1]][i - 1];
            }
        }

        vector<int> ans;

        for(auto &q : queries){

            int u = q[0], v = q[1];
            int total = 0;
            int maxi = 0;

            int LCA = getLCA(u, v);

            for(int i = 0; i < 26; i++){
                int f = freq[u][i] + freq[v][i] - 2 * freq[LCA][i];

                total += min(maxi, f);
                maxi = max(maxi, f);
            }

            ans.push_back(total);
        }

        return ans;
    }
};