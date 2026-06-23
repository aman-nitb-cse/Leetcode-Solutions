// Last updated: 6/24/2026, 3:30:27 AM
class Solution {
public:
    string toBinary(int n){
        string s = "";
        while(n){
            s.insert(s.begin(), (n&1) + '0');
            n >>= 1;
        }
        return s.size() ? s : "0";
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
    
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};