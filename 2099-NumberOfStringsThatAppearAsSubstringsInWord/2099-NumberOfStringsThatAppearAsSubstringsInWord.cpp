// Last updated: 6/25/2026, 11:13:50 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string &s : patterns){
            if(word.find(s) != -1) count++;
        }
        return count;
    }
};