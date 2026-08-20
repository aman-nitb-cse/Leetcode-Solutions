// Last updated: 8/20/2026, 8:27:07 PM
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