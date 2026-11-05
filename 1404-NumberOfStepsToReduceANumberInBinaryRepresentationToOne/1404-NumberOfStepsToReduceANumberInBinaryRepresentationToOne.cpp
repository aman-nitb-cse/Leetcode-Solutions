// Last updated: 11/6/2026, 5:03:15 AM
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