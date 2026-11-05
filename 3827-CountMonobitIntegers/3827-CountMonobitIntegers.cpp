// Last updated: 11/6/2026, 4:37:03 AM
class Solution {
public:
    int countMonobit(int n) {
        int x = log(n + 1) / log(2);
        return 1 + x;
    }
};