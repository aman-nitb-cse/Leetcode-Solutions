// Last updated: 6/24/2026, 3:32:11 AM
class Solution {
public:
    bool isVowel(char c){
        return string("aeiouAEIOU").find(c) != string::npos;
    }
    string sortVowels(string s) {
        string v = "";
        for(char &c : s){
            if(isVowel(c)) v += c;
        }
        ranges::sort(v);
        int i = 0;
        for(char &c : s){
            if(isVowel(c)) c = v[i++];
        }
        return s;
    }
};