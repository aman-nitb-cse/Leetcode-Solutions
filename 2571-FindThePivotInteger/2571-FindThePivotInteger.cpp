// Last updated: 7/18/2026, 12:25:10 AM
class Solution {
public:
    int pivotInteger(int n) {
        int suf = n * (n + 1) / 2;
        int pref = 0;

        for(int i = 1; i <= n; i++){
            pref += i;

            if(pref == suf) return i;

            suf -= i;
        }

        return -1;
    }
};