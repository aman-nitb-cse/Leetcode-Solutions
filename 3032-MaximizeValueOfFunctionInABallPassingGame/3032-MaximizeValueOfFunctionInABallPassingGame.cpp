// Last updated: 6/24/2026, 3:31:55 AM
class Solution {
public:
    using ll = long long;
    long long getMaxFunctionValue(vector<int>& next, long long k) {
        int n = next.size();
        int bits = 35;
        vector<vector<array<ll,2>>> jump(n, vector<array<ll,2>> (bits, {0, 0}));

        for(int i = 0; i < 35; i++){
            for(int j = 0; j < n; j++){
                if(i) {
                    jump[j][i][0] = jump[jump[j][i - 1][0]][i - 1][0];
                    jump[j][i][1] = jump[jump[j][i - 1][0]][i - 1][1] + jump[j][i - 1][1];
                }
                else {
                    jump[j][0] = {next[j], next[j]};
                }
            }
        }

        ll maxi = LLONG_MIN;
        for(int i = 0; i < n; i++){

            int u = i;
            ll curr = 0;

            for(int j = bits - 1; j >= 0; j--){

                if((k >> j) & 1) {
                    curr += jump[u][j][1];
                    u = jump[u][j][0];
                }
                
            }

            maxi = max(maxi, curr + i);
        }

        return maxi;
    }
};