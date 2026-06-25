// Last updated: 6/25/2026, 11:14:34 PM
class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {

        int xorA = 0;
        int xorB = 0;

        for(int x : A) xorA ^= x;
        for(int x : B) xorB ^= x;

        return xorA & xorB;
    }
};