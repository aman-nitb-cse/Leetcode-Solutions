// Last updated: 11/6/2026, 4:59:56 AM
class Solution {
public:
    string maximumBinaryString(string s) {
        int first_zero = s.find('0');
        
        if (first_zero == string::npos)  return s;
        
        int zeros = count(s.begin(), s.end(), '0');
        
        string ans(s.length(), '1');
        ans[first_zero + zeros - 1] = '0';
        
        return ans;
    }
};