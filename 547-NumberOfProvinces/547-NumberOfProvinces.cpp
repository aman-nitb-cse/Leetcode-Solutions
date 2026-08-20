// Last updated: 8/20/2026, 9:03:08 PM
class Solution {
public:
    vector<bool> visited;
    int n;

    void dfs(vector<vector<int>>& m, int city){
        visited[city] = true;

        for(int next = 0; next < n; next++){
            if(m[city][next] && !visited[next]){
                dfs(m, next);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& m) {
        n = m.size();
        visited.assign(n, false);

        int provinces = 0;

        for(int city = 0; city < n; city++){
            if(!visited[city]){
                provinces++;
                dfs(m, city);
            }
        }

        return provinces;
    }
};