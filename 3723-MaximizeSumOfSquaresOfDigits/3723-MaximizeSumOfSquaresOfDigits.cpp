// Last updated: 11/6/2026, 4:39:11 AM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        string s = "";

        if((sum + 8) / 9 > num) return "";

        for(int i = 0; i < num; i++){
            if(sum >= 9){
                s += '9';
                sum -= 9;
            }
            else {
                s += sum + '0';
                sum = 0;
            }
        }

        return s;
    }
};