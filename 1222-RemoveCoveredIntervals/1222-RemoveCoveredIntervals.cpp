// Last updated: 8/20/2026, 8:55:16 PM
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& I) {
        ranges::sort(I, [](auto &a, auto &b){
            return (a[0] == b[0]) ? a > b : a < b;
        });

        int cnt = 0;

        int s = 0, e = 0;

        for(auto &i : I){
            if(s <= i[0] && e >= i[1]) cnt++;
            else {
                s = i[0];
                e = i[1];
            }
        }

        return I.size() - cnt;
    }
};