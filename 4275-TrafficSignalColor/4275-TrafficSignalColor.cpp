// Last updated: 6/24/2026, 3:27:13 AM
class Solution {
public:
    string trafficSignal(int t) {
        if(t == 0) return "Green";
        if(t == 30) return "Orange";
        if(t > 30 && t <= 90) return "Red";
        return "Invalid";
    }
};