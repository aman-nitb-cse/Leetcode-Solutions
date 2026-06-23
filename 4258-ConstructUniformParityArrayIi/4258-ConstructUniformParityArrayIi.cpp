// Last updated: 6/24/2026, 3:27:29 AM
class Solution {
public:
    bool uniformArray(vector<int>& v) {
        int o = 0, e = 0;
        int min_odd = 1e9, min_even = 1e9;
        for(int &i : v){
            if(i&1) {
                o++;
                min_odd = min(i, min_odd);
            }
            else {
                e++;
                min_even = min(i, min_even);
            }
        }

        if(o == 0 || e == 0) return true; 
        return min_even - min_odd >= 1;
    }
};