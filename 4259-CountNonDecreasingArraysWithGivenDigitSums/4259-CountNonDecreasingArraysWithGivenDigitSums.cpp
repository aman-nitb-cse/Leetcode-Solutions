// Last updated: 6/24/2026, 3:27:28 AM
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int countArrays(vector<int>& d) {

        int n = d.size();

        vector<vector<int>> nums(51), dp(n);

        for(int i = 0; i <= 5000; i++){
            int sum = 0;

            for(int x = i; x; x /= 10){
                sum += x % 10;
            }

            nums[sum].push_back(i);
        }

        for(int x : d){
            if(nums[x].empty()) return 0;
        }

        for(int i = n - 1; i >= 0; i--){

            int m = nums[d[i]].size();

            dp[i].resize(m);

            for(int j = m - 1; j >= 0; j--){

                if(i == n - 1){

                    dp[i][j] = 1;

                }else{

                    int k = ranges::lower_bound(nums[d[i + 1]], nums[d[i]][j]) - nums[d[i + 1]].begin();

                    if(k < dp[i + 1].size()){
                        dp[i][j] = dp[i + 1][k];
                    }
                }

                if(j + 1 < m){
                    dp[i][j] += dp[i][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[0][0];
    }
};