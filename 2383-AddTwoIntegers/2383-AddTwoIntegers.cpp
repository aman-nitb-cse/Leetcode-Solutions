// Last updated: 6/25/2026, 11:12:17 PM
class Solution {
public:
    int sum(int num1, int num2) {
        if (num2 == 0) return num1;
        return sum(num1 ^ num2, (num1 & num2) << 1);
    }
};