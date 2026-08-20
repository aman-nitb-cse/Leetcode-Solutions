// Last updated: 8/20/2026, 8:58:58 PM
#define f(i, a, b) for(int i = a; i <= b; i++)

class Solution {
public:
    vector<bool> vis;
    int n;
    set<int> ans;
    bool dfs(int node, vector<vector<int>>& graph){

        vis[node] = true;

        for(int &nbr : graph[node]){
            if(!vis[nbr]){
                if(!dfs(nbr, graph)) return false;
            }
            else if(!ans.count(nbr)) return false;
        }

        ans.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n);

        f(i, 0, n - 1){
            if(!vis[i]) dfs(i, graph);
        }

        return vector<int> (ans.begin(), ans.end());
    }
};