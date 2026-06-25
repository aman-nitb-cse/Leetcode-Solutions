// Last updated: 6/25/2026, 11:13:55 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        long long ans = 0;
        int count_neg = 0;
        int mini = abs(m[0][0]);
        bool zero = false;

        for(auto &v : m){
            for(auto &i : v) {
                ans += abs(i);
                mini = min(mini, abs(i));
                if(i < 0) count_neg++;
                if(i == 0) zero = true;
            }
        }
        return ((count_neg & 1) && !zero) ? ans - 2 * mini : ans;
    }
};