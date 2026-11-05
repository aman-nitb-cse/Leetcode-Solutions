// Last updated: 11/6/2026, 5:01:16 AM
class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int sum = 0, n = a.size();
        for(int i = 0; i < n; i++){
            sum += a[i][i] + a[i][n - i - 1];
        }
        return sum - a[n/2][n/2] * (n & 1);
    }
};