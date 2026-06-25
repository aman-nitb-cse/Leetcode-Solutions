// Last updated: 6/25/2026, 11:14:10 PM
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& t) {
        bool x = false, y = false, z = false;

        for(auto &v : tri){
            if(v[0] > t[0] || v[1] > t[1] || v[2] > t[2]) continue;

            x |= (v[0] == t[0]);
            y |= (v[1] == t[1]);
            z |= (v[2] == t[2]);
        }
        return x && y && z;
    }
};