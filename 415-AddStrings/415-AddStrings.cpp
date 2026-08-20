// Last updated: 8/20/2026, 9:06:23 PM
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0") return num2;
        if(num2 == "0") return num1;
        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end());
        if(num2.size() > num1.size()) swap(num1, num2);
        // num1 > num2
        int i, carry = 0;
        for(i = 0; i < num2.size(); i++){
            int a = num1[i] - '0';
            int b = num2[i] - '0';

            int sum = a + b + carry;
            carry = sum / 10;
            char c = (sum % 10) + '0';
            num1[i] = c;
        }
        while(i < num1.size()){
            int sum = carry + num1[i] - '0';
            carry = sum / 10;
            char c = (sum % 10) + '0';
            num1[i++] = c;
        }
        if(carry & 1) num1 += '1';
        reverse(num1.begin(), num1.end());
        return num1;
    }
};