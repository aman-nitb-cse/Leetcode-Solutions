// Last updated: 8/20/2026, 9:17:09 PM
class Solution {
public:
    string addBinary(string a, string b, int carry = 0) {

        if(b.empty()) swap(a, b);
        // a is empty
        if(a.empty()){

            // Carry = 0
            if(carry == 0) return b;

            // b is empty, carry is 1
            if(b.empty()) return "1";
            
            // b is not empty, and carry is 1
            int sum = (b.back() - '0') + carry;
            b.pop_back();
            char val = (sum & 1) + '0';
            return addBinary(a, b, sum >> 1) + val;
        }

        int sum = (b.back() - '0') + ((a.back() - '0')) + carry;
        a.pop_back();
        b.pop_back();
        char val = (sum & 1) + '0';
        return addBinary(a, b, sum >> 1) + val;
    }
};