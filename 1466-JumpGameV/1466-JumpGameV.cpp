// Last updated: 6/25/2026, 11:16:43 PM
class Solution {
public:
    vector<int> dp;

    int dfs(vector<int>& arr, int i, int d){

        if(dp[i] != -1) return dp[i];

        int ans = 1;

        // right
        for(int j = i + 1; j <= min(i + d, (int)arr.size() - 1); j++){

            if(arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(arr, j, d));
        }

        // left
        for(int j = i - 1; j >= max(0, i - d); j--){

            if(arr[j] >= arr[i]) break;

            ans = max(ans, 1 + dfs(arr, j, d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        dp.assign(n, -1);

        int ans = 1;

        for(int i = 0; i < n; i++){

            ans = max(ans, dfs(arr, i, d));
        }

        return ans;
    }
};