// Last updated: 11/6/2026, 4:46:05 AM
class Solution {
public:
    string getEncryptedString(string s, int k) {
        k %= s.size();
        return s.substr(k) + s.substr(0, k);
    }
};