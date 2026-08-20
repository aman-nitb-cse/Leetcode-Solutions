// Last updated: 8/20/2026, 9:06:04 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), 
            [](vector<int> a, vector<int> b){
                return a[1] < b[1]; 
            }
        );
        int count = 0;
        int prev_end = I[0][1];
        for(int i = 1; i < I.size(); i++){
            if(I[i][0] < prev_end) count++;
            else prev_end = I[i][1];
        }
        return count;
    }
};