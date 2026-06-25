// Last updated: 6/25/2026, 11:13:52 PM
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& O) {
        vector<int> LIS;

        for(int i = 0; i < O.size(); i++){

            int pos = ranges::upper_bound(LIS, O[i]) - LIS.begin();

            if(pos == LIS.size()) LIS.push_back(O[i]);
            else LIS[pos] = O[i];

            O[i] = pos + 1;
        }

        return O;
    }
};