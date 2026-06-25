// Last updated: 6/25/2026, 11:18:27 PM
class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a + b != b + a) return "";
        return a.substr(0, gcd(a.size(), b.size()));
    }
};