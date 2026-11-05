// Last updated: 11/6/2026, 4:31:48 AM
class Solution {
public:
    int largestInteger(int n, int s) {
        int d = s / 9;

        string x(d, '9');

        if(s % 9) x += '0' +  (s % 9);

        while(x.size() < n) x += '0';

        if(x.size() > n) return -1;

        return stoi(x);
    }
};