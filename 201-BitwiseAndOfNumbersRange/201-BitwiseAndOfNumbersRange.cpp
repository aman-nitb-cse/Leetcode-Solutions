// Last updated: 8/20/2026, 9:11:58 PM
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        return rangeBitwiseAnd(left >> 1, right >> 1) << 1;
    }
};