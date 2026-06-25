// Last updated: 6/25/2026, 11:12:42 PM
class Solution {
public:
    int countOperations(int a, int b) {
        if(a == 0 || b == 0) return 0;
        if(a >= b) return 1 + countOperations(a - b, b);
        return 1 + countOperations(a, b - a);
    }
};