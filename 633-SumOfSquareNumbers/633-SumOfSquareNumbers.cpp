// Last updated: 8/20/2026, 9:02:07 PM
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long s = 0, e = sqrt(c);
        while(s <= e){
            long long sq = (s * s) + (e * e);
            if(sq == c) return true;
            else if(sq < c) s++;
            else e--;
        }
        return false;
    }
};