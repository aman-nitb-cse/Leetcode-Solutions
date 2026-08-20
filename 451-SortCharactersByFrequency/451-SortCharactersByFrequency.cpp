// Last updated: 8/20/2026, 9:05:32 PM
class Solution {
public:
    string frequencySort(string s) {
        map <char, int> hash;
        for(char &c : s) hash[c]++;

        multimap <int, char> temp;
        for(auto &i : hash){
            temp.insert({i.second, i.first});
        }
        s = "";
        for(auto i = temp.rbegin(); i != temp.rend(); i++){
            s.append(i->first, i->second);
        }
        return s;
    }
};