// Last updated: 6/24/2026, 3:29:44 AM
class Solution {
public:
    vector<vector<int>> graph;
    const int mod = 1e9 + 7;
    int dfs(int node, int par){

        int depth = 0;
        
        for(int nbr : graph[node]){
            if(nbr ^ par){
                depth = max(depth, dfs(nbr, node));
            }
        }

        return ++depth;
    }
    long long power(long long a,long long b){
        long long ans = 1;

        while(b){
            if(b & 1) ans = ans * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // total number of nodes

        graph.resize(n + 1);

        for(auto &ed : edges){
            graph[ed[0]].push_back(ed[1]);
            graph[ed[1]].push_back(ed[0]);
        }

        int edg = dfs(1, -1) - 1;

        return edg ? power(2, edg - 1) : 0;
    }
};