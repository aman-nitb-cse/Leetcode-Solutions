// Last updated: 11/6/2026, 5:04:38 AM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double h = hour % 12 + minutes / 60.0;

        double m = minutes / 5.0;

        double angle = abs(h - m) * 30;

        return min(angle, 360 - angle);
    }
};