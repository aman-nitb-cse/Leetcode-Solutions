// Last updated: 6/25/2026, 11:19:10 PM
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for(int i = num.size() - 1; i >= 0; i--){
            int sum = num[i] + carry + (k % 10);
            k /= 10;
            num[i] = sum % 10;
            carry = sum / 10;
        }
        while(k + carry){
            int sum = (k % 10) + carry;
            k /= 10;
            carry = sum / 10;
            num.insert(num.begin(), sum % 10);
        }
        return num;
    }
};