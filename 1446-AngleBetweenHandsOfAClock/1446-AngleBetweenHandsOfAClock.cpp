// Last updated: 6/25/2026, 11:16:55 PM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double h = hour % 12 + minutes / 60.0;

        double m = minutes / 5.0;

        double angle = abs(h - m) * 30;

        return min(angle, 360 - angle);
    }
};