// Last updated: 6/25/2026, 11:10:38 PM
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string &s : details){
            if(stoi(s.substr(11, 2)) > 60) count++;
        }
        return count;
    }
};