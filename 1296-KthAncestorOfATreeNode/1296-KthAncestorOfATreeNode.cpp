// Last updated: 6/25/2026, 11:17:50 PM
class TreeAncestor {
public:
    vector<vector<int>> jump;
    TreeAncestor(int n, vector<int>& parent) {

        jump.assign(n, vector<int> (20, -1));

        for(int i = 1; i < n; i++){
            jump[i][0] = parent[i];
        }

        for(int j = 1; j < 20; j++){
            for(int node = 0; node < n; node++){
                if(jump[node][j - 1] != -1) jump[node][j] = jump[jump[node][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20 && node != -1; i++){
            if((k >> i) & 1) node = jump[node][i];
        }
        return node;
    }
};