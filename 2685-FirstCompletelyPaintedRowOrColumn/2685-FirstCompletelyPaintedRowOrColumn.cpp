// Last updated: 7/2/2026, 11:38:09 PM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();

        vector<int> row(m * n + 1), col(m * n + 1);

        vector<int> rowcnt(m), colcnt(n);


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }

        for(int i = 0; i < arr.size(); i++){

            if(++rowcnt[row[arr[i]]] == n || ++colcnt[col[arr[i]]] == m) return i;
            
        }
        return -1;
    }
};