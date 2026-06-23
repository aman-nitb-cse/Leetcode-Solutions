// Last updated: 6/24/2026, 3:29:46 AM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(z - y) > abs(z - x)) return 1;
        else if(abs(z - y) < abs(z - x)) return 2;
        return 0;
    }
};