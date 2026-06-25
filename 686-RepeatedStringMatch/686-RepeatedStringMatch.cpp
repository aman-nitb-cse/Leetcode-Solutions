// Last updated: 6/25/2026, 11:37:17 PM
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;
        while(a.size() <= 2 * temp.size() + b.size()){
            if(a.find(b) < a.size()) return count;
            count++;
            a += temp;
        }
        return -1;
    }
};