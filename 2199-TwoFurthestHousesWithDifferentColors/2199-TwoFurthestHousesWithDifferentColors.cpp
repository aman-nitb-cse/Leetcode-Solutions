// Last updated: 6/25/2026, 11:13:13 PM
class Solution {
public:
    int maxDistance(vector<int>& v) {
        for(int d = v.size() - 1; d > 0; d--){
            for(int i = 0; i + d < v.size(); i++){
                if(v[i] != v[i + d]) return d;
            }
        }
        return 0;
    }
};