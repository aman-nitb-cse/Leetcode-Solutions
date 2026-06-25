// Last updated: 6/25/2026, 11:16:21 PM
class Solution {
public:
    int numSteps(string s, char carry = '0') {

        // Even case
        if(s.back() == '0') {
            if(carry == '1'){
                s.back() = '1';
                return numSteps(s);
            }
            else {
                s.pop_back();
                return 1 + numSteps(s);
            }
        }

        // destination
        if(s.size() == 1) return carry == '1'; 

        // odd case carry 1
        s.pop_back();
        return 1 + numSteps(s, '1') + (carry == '0');
    }
};