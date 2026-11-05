// Last updated: 11/6/2026, 4:59:47 AM
class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int c) {
        sort(b.begin(), b.end(), 
            [](vector<int> x, vector<int> y){
                return x[1] > y[1];
            }
        );
        int units = 0;
        for(int i = 0; c > 0 && i < b.size(); i++){
            if(c >= b[i][0]) units += b[i][0] * b[i][1];
            else units += c * b[i][1];
            c -= b[i][0];
        }
        return units;
    }
};