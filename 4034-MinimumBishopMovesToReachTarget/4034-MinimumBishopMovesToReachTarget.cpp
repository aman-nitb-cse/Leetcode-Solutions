// Last updated: 11/6/2026, 4:31:12 AM
class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        int a = s[0], b = s[1];
        int x = t[0], y = t[1];

        if(a == x && b == y) return 0;
        if((a + b) % 2 != (x + y) % 2) return -1;
        if(abs(x - a) == abs(y - b)) return 1;
        return 2;
    }
};