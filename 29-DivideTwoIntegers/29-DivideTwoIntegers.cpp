// Last updated: 8/20/2026, 9:19:01 PM
class Solution {
public:
    int divide(int a, int b) {
        // bool ispositive = true;
        // if((a < 0 and b > 0) or (a > 0 and b < 0)) ispositive = false;
        bool sign = (a > 0) ^ (b > 0);
        long long x = abs(1LL * a), y  = abs(1LL * b);
        if(x < y) return 0;
        long long count = 0;
        for(int i = 0; x >= y << i; i++){
            x -= y << i;
            count += 1 << i;
        }
        long long ans =  count + divide(x, y);
        if(!sign){
            return (ans > INT_MAX) ? INT_MAX : ans;
        }
        return (- ans < INT_MIN) ? INT_MIN : - ans; 
    }
};