// Last updated: 6/30/2026, 2:15:21 PM
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> C(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            C[i][0] = C[i][i] = 1;
            for(int j = 1; j < i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = (ans + C[n - 1][i] * nums[i]) % 10;
        }

        return ans;
    }
};