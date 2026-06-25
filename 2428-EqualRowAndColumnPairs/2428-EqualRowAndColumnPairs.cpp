// Last updated: 6/25/2026, 11:12:03 PM
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v = grid;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) 
                swap(v[i][j], v[j][i]);
        }

        int count = 0;
        for(auto &r : grid){
            for(auto &c : v){
                count += (r == c);
            }
        }
        return count;
    }
};