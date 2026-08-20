// Last updated: 8/20/2026, 9:10:03 PM
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};