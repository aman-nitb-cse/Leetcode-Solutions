// Last updated: 6/25/2026, 11:12:21 PM
class Solution {
public:
    int percentageLetter(string s, char c) {
        int count = 0;
        for(char &i : s){
            if(i == c) count++;
        }
        return (count * 100)/s.size();
    }
};