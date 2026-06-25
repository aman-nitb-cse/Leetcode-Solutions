// Last updated: 6/25/2026, 11:21:11 PM
class Solution {
public:
    string rotate(int n){
        string s = to_string(n);
        for(char &c : s){
            if(c == '2') c = '5';
            else if(c == '5') c = '2';
            else if(c == '6') c = '9';
            else if(c == '9') c = '6';
            else if(c == '3' || c == '4' || c == '7') return to_string(n);
        }
        return s;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            count += (to_string(i) != rotate(i)); 
            // cout << to_string(i) << ' ' << rotate(i) << endl; 
        }
        return count;
    }
};