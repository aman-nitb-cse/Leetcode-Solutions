// Last updated: 11/6/2026, 4:31:36 AM
class Solution {
public:
    int f(string s){
        return 3600 * stoi(s.substr(0, 2)) + 60 * stoi(s.substr(3, 2)) + stoi(s.substr(6, 2));
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return f(endTime) - f(startTime);
    }
};