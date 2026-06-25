// Last updated: 6/25/2026, 11:17:04 PM
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0, b = 0;
        int i = 0;
        while(n){

            // separate digit
            int d = n % 10; 
            n /= 10;

            // Borrow
            if(d < 2 && n){
                d += 10;
                n--;
            }

            a += pow(10, i) * (d / 2);
            b += pow(10, i) * (d - d / 2);
            i++;
        }
        return {a, b};
    }
};