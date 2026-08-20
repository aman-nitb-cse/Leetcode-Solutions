// Last updated: 8/20/2026, 9:01:43 PM
class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> r;
        queue<int> d;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R') r.push(i);
            else if(s[i] == 'D') d.push(i);
        }

        while(!r.empty() && !d.empty()){
            int _r = r.front(); r.pop();
            int _d = d.front(); d.pop();

            if(_r < _d) r.push(_r + s.size());
            else d.push(_d + s.size());
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};