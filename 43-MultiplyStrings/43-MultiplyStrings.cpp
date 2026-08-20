// Last updated: 8/20/2026, 9:18:27 PM
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0") return "0";
        if(num2 == "0") return "0";
        int digit = * num1.rbegin() - '0';
        num1.erase(num1.end() - 1);

        string temp = "";
        int carry = 0;
        for(int i = num2.size() - 1; i >= 0; i--){
            int c = num2[i] - '0';
            int sum = c * digit + carry;
            carry = sum / 10;
            temp.insert(temp.begin(), sum % 10 + '0');
        }
        if(carry) temp.insert(temp.begin(), carry + '0');
        if(num1.empty()) return temp;

        carry = 0;
        string ans = multiply(num1, num2) + "0";
        int i, j;
        for(i = ans.size() - 1, j = temp.size() - 1; i >= 0 and j >= 0; i--, j--){
            int sum = temp[j] - '0' + ans[i] - '0' + carry;
            carry = sum / 10;
            ans[i] = sum % 10 + '0';
        }
        if(i >= 0){
            while(i >= 0){
                int sum = ans[i] - '0' + carry;
                carry = sum / 10;
                ans[i] = sum % 10 + '0';
                i--;
            }
        }
        else if(j >= 0){
            while(j >= 0){
                int sum = temp[j] + carry;
                carry = sum / 10;
                ans.insert(ans.begin(), sum % 10 + '0');
                j--;
            }
        }
        if(carry) ans.insert(ans.begin(), carry + '0');
        return ans;
    }
};