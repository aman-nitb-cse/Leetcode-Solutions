// Last updated: 6/25/2026, 11:12:44 PM
class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        ranges::sort(s);
        if(num > 0){
            if(s[0] == '0'){
                for(int i = 0; i < s.size(); i++){
                    if(s[i] != '0'){
                        swap(s[0], s[i]);
                        break;
                    }
                }
            }
        }
        else {
            ranges::reverse(s);
            s = "-" + s;
        }
        return stoll(s);
    }
};