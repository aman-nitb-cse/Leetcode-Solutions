// Last updated: 6/24/2026, 3:31:32 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        int d = 0, a = 0;
        for(int i = 0; i < v.size(); i++){
            int _d = v[i][0] * v[i][0] + v[i][1] * v[i][1];
            int _a = v[i][0] * v[i][1];
            if(_d > d || (_d == d && _a > a)){
                d = _d;
                a = _a;
            }
        }
        return a;
    }
};