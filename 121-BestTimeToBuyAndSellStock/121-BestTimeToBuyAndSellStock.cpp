// Last updated: 8/20/2026, 9:14:22 PM
class Solution {
public:
    int maxProfit(vector<int>& v) {
        int maxi = 0;
        int s = 0, e = 1;
        while(e < v.size()){
            maxi = max(v[e] - v[s], maxi);
            if(v[e] <= v[s]) s = e;
            e++;
        }
        return maxi;
    }
};