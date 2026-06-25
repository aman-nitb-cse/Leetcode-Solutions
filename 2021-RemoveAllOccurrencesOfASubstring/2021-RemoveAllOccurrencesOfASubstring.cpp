// Last updated: 6/25/2026, 11:14:11 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) < s.size()){   
            s.erase(s.find(part) , part.size());    
        }
        return s ;
    }
};