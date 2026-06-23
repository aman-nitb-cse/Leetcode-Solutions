// Last updated: 6/24/2026, 3:30:14 AM
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int max_time = 0, index = 0, prev_time = 0;
        for(vector<int> &v : events){
            int time = v[1] - prev_time;
            prev_time = v[1];
            if((time > max_time) || (time == max_time && v[0] < index)){
                max_time = time;
                index = v[0];
            }
        }
        return index;
    }
};