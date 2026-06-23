// Last updated: 6/24/2026, 3:30:46 AM
class Solution {
public:
    string getEncryptedString(string s, int k) {
        k %= s.size();
        return s.substr(k) + s.substr(0, k);
    }
};