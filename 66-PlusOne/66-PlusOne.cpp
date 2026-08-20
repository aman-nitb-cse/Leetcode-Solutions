// Last updated: 8/20/2026, 9:17:16 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int carry = 1;
        for(int i = v.size() - 1; i >= 0; i--){
            int sum = v[i] + carry;
            carry = sum / 10;
            v[i] = sum % 10;
            if(!carry) return v;
        }
        if(carry) v.insert(v.begin(), 1);
        return v;
    }
};