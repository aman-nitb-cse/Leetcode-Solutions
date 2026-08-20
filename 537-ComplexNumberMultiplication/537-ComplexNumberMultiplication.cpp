// Last updated: 8/20/2026, 9:03:19 PM
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x = stoi(a);
        int y = stoi(a.substr(a.find('+') + 1));
        int p = stoi(b);
        int q = stoi(b.substr(b.find('+') + 1));
        return to_string(x * p - y * q) + "+" + to_string(x * q + y * p) + "i";
    }
};