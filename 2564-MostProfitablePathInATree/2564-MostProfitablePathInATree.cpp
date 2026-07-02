// Last updated: 7/2/2026, 11:38:28 PM
class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    vector<int> par;

    void dfs(int node, int p){

        par[node] = p;

        for(int &nbr : g[node]){
            if(nbr != p){
                dfs(nbr, node);
            }
        }
    }
    int solve(int alice, int bob, vector<int>& a){

        if(g[alice].size() == 1 && alice) return a[alice] * !vis[alice];

        // profit calculation

        int profit = 0;

        if(alice == bob) profit += a[alice] / 2;
        else profit += a[alice] * !vis[alice];

        // remember for backtrack 

        bool va = vis[alice], vb = vis[bob];

        // explore all paths (alice childs) x (bob parent)

        vis[alice] = vis[bob] = true;

        int maxi = INT_MIN;

        for(int &nbr : g[alice]){
            if(nbr != par[alice]){
                maxi = max(maxi, solve(nbr, bob ? par[bob] : bob, a));
            }
        }

        // backtrack

        vis[alice] = va;
        vis[bob] = vb;

        // return

        return profit + maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& a) {

        // initialization

        int n = edges.size() + 1;

        g.resize(n);
        vis.resize(n);
        par.resize(n);

        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        // actual solution 
        return solve(0, bob, a);
    }
};