// Last updated: 6/25/2026, 11:20:41 PM
class Solution {
public:
    vector<vector<int>> G;
    vector<int> sum, childs, ans;

    void dfs1(int node, int par){

        childs[node] = 1;

        for(int &c : G[node]){
            if(c != par){
                dfs1(c, node);

                sum[node] += sum[c] + childs[c];
                childs[node] += childs[c];
            }
        }
    }

    void dfs2(int node, int par, int n, int up = 0){

        ans[node] = sum[node] + up;

        for(int &c : G[node]){
            if(c != par){

                int newUp = ans[node] - sum[c] + n - 2 * childs[c];

                dfs2(c, node, n, newUp);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& E) {

        G.resize(n);
        sum.assign(n, 0);
        childs.assign(n, 0);
        ans.assign(n, 0);

        for(auto &e : E){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1, n);

        return ans;
    }
};