// Last updated: 6/25/2026, 11:18:22 PM
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int c) {
        int diff[1001] = {0};

        for(auto &i : trips){
            diff[i[1]] += i[0];
            diff[i[2]] -= i[0];
        }
        int sum = 0;
        return all_of(begin(diff), end(diff), 
            [&](int x){
                sum += x;
                return sum <= c;
            }
        );
    }
};