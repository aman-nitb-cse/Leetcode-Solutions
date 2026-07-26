// Last updated: 7/26/2026, 8:12:10 AM
1class Solution {
2public:
3    int largestInteger(int n, int s) {
4        int d = s / 9;
5
6        string x(d, '9');
7
8        if(s % 9) x += '0' +  (s % 9);
9
10        while(x.size() < n) x += '0';
11
12        if(x.size() > n) return -1;
13
14        return stoi(x);
15    }
16};