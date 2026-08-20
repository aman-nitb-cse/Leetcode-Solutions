// Last updated: 8/20/2026, 9:09:43 PM
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(isBadVersion(n)) n--;
        return ++n;
    }
};