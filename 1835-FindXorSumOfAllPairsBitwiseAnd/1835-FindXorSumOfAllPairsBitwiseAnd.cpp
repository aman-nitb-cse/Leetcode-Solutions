// Last updated: 11/6/2026, 4:58:21 AM
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