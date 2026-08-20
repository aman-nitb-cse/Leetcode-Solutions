// Last updated: 8/20/2026, 9:07:45 PM
class Solution {
public:
    int power(int a, int x, int p = 0){ // returns a^(x * 10^y) % 10
        a %= 1337;
        if(x == 0) return 1;
        if(p == 0){
            if(x == 1) return a;
            return (power(a * a, x / 2) * power(a, x & 1)) % 1337;
        }
        return power(power(a, 10), x, p - 1);
    }
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int num = 1, n = b.size();
        for(int i = n - 1; i >= 0; i--){
            num *= power(a, b[i], n - i - 1); 
            num %= 1337;
        }
        return num;
    }
};