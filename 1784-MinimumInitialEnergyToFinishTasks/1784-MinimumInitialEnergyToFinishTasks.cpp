// Last updated: 6/25/2026, 11:15:21 PM
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        ranges::sort(
            tasks,
            [](auto &a, auto &b){
                return a[1] - a[0] > b[1] - b[0];
            }
        );

        int add = 0, rem = 0;
        for(auto &q : tasks){
            int cost = q[0];
            int min = q[1];

            if(min > rem) {
                add += min - rem;
                rem = min;
            }

            rem -= cost;
        }
        return add;
    }
};