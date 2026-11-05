// Last updated: 11/6/2026, 5:10:16 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](auto &a){
            return (a[0] * a[0]) + (a[1] * a[1]);
        };

        ranges::sort(points,
            [&](auto &a, auto &b){
                return dist(a) < dist(b);
            }
        );
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};