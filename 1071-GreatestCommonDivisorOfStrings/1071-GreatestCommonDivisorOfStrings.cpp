// Last updated: 11/6/2026, 5:08:04 AM
class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a + b != b + a) return "";
        return a.substr(0, gcd(a.size(), b.size()));
    }
};