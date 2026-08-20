// Last updated: 8/20/2026, 9:16:54 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        unordered_set <int> row, column;
        int m = a.size(), n = a[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }

        for(int i : row){
            for(int j = 0; j < n; j++){
                a[i][j] = 0;
            }
        }
        for(int j : column){
            for(int i = 0; i < m; i++){
                a[i][j] = 0;
            }
        }
    }
};