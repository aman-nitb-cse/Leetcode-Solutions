// Last updated: 8/20/2026, 8:59:07 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(int node, vector<vector<int>>& graph){
        v.push_back(node);

        if(node == graph.size() - 1) ans.push_back(v);

        for(int &nbr : graph[node]){
            dfs(nbr, graph);
        }

        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return ans;
    }
};