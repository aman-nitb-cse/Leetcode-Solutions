// Last updated: 6/25/2026, 11:13:40 PM
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool dfs(int n, int source, int destination){
        if(visited[source]) return false;
        if(source == destination) return true;
        visited[source] = true;
        for(int& nbr : graph[source]){
            if(dfs(n, nbr, destination)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        visited.resize(n);
        for(auto &v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        return dfs(n, source, destination);
    }
};