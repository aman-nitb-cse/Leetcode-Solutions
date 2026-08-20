// Last updated: 8/20/2026, 9:07:49 PM
class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1, e = num;
        while(s <= e){
            long long mid = s + (e - s) / 2;
            long long sq = mid * mid;
            if(sq == num) return true;
            if(sq < num) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};