// Last updated: 6/24/2026, 3:31:07 AM
class Solution {
public:
    string getSmallestString(string s, int k) {

        for(char &c : s){

            int d = c - 'a';
            d = min(d, 26 - d);

            if(d <= k){
                k -= d;
                c = 'a';
            }
            else{
                c -= k;
                break;
            }
        }

        return s;
    }
};