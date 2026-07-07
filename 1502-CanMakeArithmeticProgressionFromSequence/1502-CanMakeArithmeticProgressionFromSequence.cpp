// Last updated: 7/8/2026, 1:05:07 AM
1class Solution {
2public:
3    int pivotInteger(int n) {
4        int suf = n * (n + 1) / 2;
5        int pref = 0;
6
7        for(int i = 1; i <= n; i++){
8            pref += i;
9
10            if(pref == suf) return i;
11
12            suf -= i;
13        }
14
15        return -1;
16    }
17};