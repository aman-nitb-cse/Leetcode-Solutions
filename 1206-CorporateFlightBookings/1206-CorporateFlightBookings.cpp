// Last updated: 6/25/2026, 11:18:14 PM
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bk, int n) {
        vector<int> diff(n);

        for(auto &q : bk){
            diff[q[0] - 1] += q[2];
            if(q[1] != n) diff[q[1]] -= q[2];
        }

        for(int i = 1; i < n; i++){
            diff[i] += diff[i - 1];
        }
        return diff;
    }
};