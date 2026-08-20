// Last updated: 8/20/2026, 9:17:01 PM
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int s = 1, e = x;
        int ans = 1;
        int mid;
        while(s <= e){
            mid = s + (e - s) / 2; 
            if(mid == x / mid) return mid;
            if(mid < x / mid){
                s = mid + 1;
                ans = mid;
            } 
            else e = mid - 1;
        }
        return ans;
    }
};