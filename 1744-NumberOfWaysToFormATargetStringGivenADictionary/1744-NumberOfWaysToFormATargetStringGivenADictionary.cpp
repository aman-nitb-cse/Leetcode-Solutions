// Last updated: 8/20/2026, 8:50:49 PM
class Solution {
public:
    int count[26][1000];
    int dp[1000][1000];
    int mod = 1e9 + 7;

    int solution(int index, int curr, string& target, int maxi) {

        if (index == target.size()) {
            return 1;
        }

        if (curr == maxi) {
            return 0;
        }

        if (dp[index][curr] != -1) {
            return dp[index][curr];
        }

        long long take = 0;

        if (count[target[index] - 'a'][curr] != 0) {
            take = (1LL * count[target[index] - 'a'][curr] *
                    solution(index + 1, curr + 1, target, maxi)) %
                   mod;
        }

        long long nottake = solution(index, curr + 1, target, maxi);
        return dp[index][curr] = (take + nottake) % mod;
    }
    int numWays(vector<string>& words, string target) {

        int n = words.size();
        int m = words[0].size();
        memset(count, 0, sizeof(count));
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count[words[i][j] - 'a'][j]++;
            }
        }

        return solution(0, 0, target, m);
    }
};