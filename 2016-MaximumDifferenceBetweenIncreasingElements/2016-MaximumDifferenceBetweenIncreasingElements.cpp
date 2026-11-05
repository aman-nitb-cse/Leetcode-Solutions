// Last updated: 11/6/2026, 4:55:48 AM
class Solution {
public:
    int maximumDifference(vector<int>& v) {
        int max_dif = 0;
        int s = 0, e = 1;
        while(e < v.size()){
            max_dif = max(max_dif, v[e] - v[s]);
            if(v[e] <= v[s]) s = e;
            e++;
        }
        return max_dif ? max_dif : -1;
    }
};