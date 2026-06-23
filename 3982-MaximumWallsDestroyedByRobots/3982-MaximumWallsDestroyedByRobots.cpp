// Last updated: 6/24/2026, 3:29:17 AM
class Solution {
public:
    int count(vector<int>& walls, int left, int right){
        return ranges::upper_bound(walls, right) - ranges::lower_bound(walls, left);
    }

    int maxWalls(vector<int>& robots, vector<int>& range, vector<int>& walls) {
        ranges::sort(walls);

        vector<pair<int,int>> v;
        for(auto [pos, r] : views::zip(robots, range)) 
            v.push_back({pos, r});

        ranges::sort(v);

        int prev_left = 0, last_pos = 0, prev_right = 0, last_right = 0;

        for(int i = 0; i < v.size(); i++){
            auto [pos, r] = v[i];

            int left = max(pos - r, last_pos + 1);
            int right = min(pos + r, (i + 1 == v.size()) ? INT_MAX : v[i + 1].first - 1);

            // <==, <==
            int take_left = prev_left + count(walls, left, pos);

            // ==>, <==
            int merge_left = prev_right + count(walls, max(left, last_right + 1), pos);

            // ????,  ==>
            int take_right = max(prev_left, prev_right) + count(walls, pos, right);

            // for next
            last_pos = pos;
            last_right = right;
            prev_left = max(take_left, merge_left);
            prev_right = take_right;
        }

        return max(prev_left, prev_right);
    }
};