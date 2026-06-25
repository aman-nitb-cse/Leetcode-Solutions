// Last updated: 6/25/2026, 11:17:25 PM
class Solution {
public:
    int visit(int x, int y){
        return min(x, y) + abs(x - y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int time = 0;
        for(int i = 1; i < p.size(); i++){
            time += visit(abs(p[i - 1][0] - p[i][0]), abs(p[i - 1][1] - p[i][1]));
        }
        return time;
    }
};