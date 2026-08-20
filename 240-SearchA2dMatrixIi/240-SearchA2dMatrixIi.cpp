// Last updated: 8/20/2026, 9:10:17 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size(), n = a[0].size();
        int r = 0, c = n - 1;

        while(r < m && c >= 0){
            int val = a[r][c];

            if(t == val) return true;
            if(t < val) c--;
            else r++;
        }
        return false;
    }
};