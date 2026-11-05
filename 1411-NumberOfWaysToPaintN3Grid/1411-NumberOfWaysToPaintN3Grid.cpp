// Last updated: 11/6/2026, 5:03:06 AM
class Solution {
public:
    const int mod = 1e9 + 7;

    int numOfWays(int n) {
        long long aba = 6, abc = 6; 

        while(--n){
            long long newAba = (3 * aba + 2 * abc) % mod;
            long long newAbc = (2 * aba + 2 * abc) % mod;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % mod;
    }
};