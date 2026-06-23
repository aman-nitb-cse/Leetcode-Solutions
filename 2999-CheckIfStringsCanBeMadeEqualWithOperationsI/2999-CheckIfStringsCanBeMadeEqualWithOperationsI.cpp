// Last updated: 6/24/2026, 3:32:01 AM
class Solution {
public:
    bool canBeEqual(string a, string b) {
        if(a[0] != b[0]) swap(a[0], a[2]);
        if(a[1] != b[1]) swap(a[1], a[3]);
        // 0th and 1th char become equal
        return a == b;
    }
};