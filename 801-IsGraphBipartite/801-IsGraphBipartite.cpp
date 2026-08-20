// Last updated: 8/20/2026, 8:59:26 PM
class Solution {
public:
    vector<int> vis;

    bool dfs(vector<vector<int>>& graph, int node){

        for(int &nbr : graph[node]){
            if(vis[nbr] == -1){
                vis[nbr] = !vis[node];
                if(dfs(graph, nbr)) return true;
            }
            else if(vis[node] == vis[nbr]) return true;
        }

        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        vis.assign(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(dfs(graph, i)) return false;
            }
        }

        return true;
    }
};