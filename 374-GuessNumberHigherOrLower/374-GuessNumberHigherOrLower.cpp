// Last updated: 8/20/2026, 9:07:37 PM
class Solution {
public:
    int guessNumber(int n, int s = 1) {
        int mid = s + (n - s) / 2;
        int _guess = guess(mid);
        if(_guess == 0) return mid;
        if(_guess == 1) return guessNumber(n, mid + 1);
        return guessNumber(mid - 1);
    }
};