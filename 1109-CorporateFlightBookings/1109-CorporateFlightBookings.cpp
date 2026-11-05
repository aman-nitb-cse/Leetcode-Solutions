// Last updated: 11/6/2026, 5:07:40 AM
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