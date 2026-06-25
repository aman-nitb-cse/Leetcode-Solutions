// Last updated: 6/25/2026, 11:16:23 PM
class Solution {
public:
    string getHappyString(int n, int k, char prev = 0) {
        if(n == 0) return "";
        int x = 1 << (n - 1);
        int p = (prev ? 2 : 3);
        if(k > p * x) return "";

        int div = (k - 1) / x;
        int rem = (k - 1)% x + 1;
        char c;

        if(prev == 'a') c = (div ? 'c' : 'b');
        else if(prev == 'b') c = (div ? 'c' : 'a');
        else if(prev == 'c') c = (div ? 'b' : 'a');
        else c = 'a' + div;

        return c + getHappyString(n - 1, rem, c);
    }
};