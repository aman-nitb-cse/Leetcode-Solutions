// Last updated: 11/6/2026, 4:42:36 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z - y) > abs(z - x)) return 1;
        else if(abs(z - y) < abs(z - x)) return 2;
        return 0;
    }
};