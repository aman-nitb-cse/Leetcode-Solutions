// Last updated: 6/24/2026, 3:28:14 AM
class Solution {
public:
    int countMonobit(int n) {
        int x = log(n + 1) / log(2);
        return 1 + x;
    }
};