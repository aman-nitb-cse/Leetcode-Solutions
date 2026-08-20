// Last updated: 8/20/2026, 9:06:34 PM
class Solution {
public:
    char to_char(int x){
        if(x <= 9) return x + '0';
        return 'a' + (x - 10);
    }
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        while(num){
            int x = num & 15;
            num = (num >> 4) & ((1 << 28) - 1);
            ans = to_char(x) + ans;
        }
        return ans;
    }
};