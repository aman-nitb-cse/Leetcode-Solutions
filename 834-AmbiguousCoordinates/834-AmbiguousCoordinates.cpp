// Last updated: 6/25/2026, 11:20:49 PM
class Solution {
public:
    bool isValid(string s){
        if(s.size() == 1) return true;
        if(s.front() == '0' && s.back() == '0') return false;
        if(s.front() == '0') return s[1] == '.';
        if(s.back() == '0') return ranges::count(s, '.') == 0;
        return true;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        vector<string> v1;
        vector<string> v2;

        s = s.substr(1, s.size()-2);   // remove parentheses
        int n = s.size();

        for(int i = 1; i < n; i++){
            
            // left
            string left = s.substr(0, i);
            v1.push_back(left);
            for(int j = 1; j < left.size(); j++){
                v1.push_back(left);
                v1.back().insert(j, ".");
            }

            // right
            string right = s.substr(i);
            v2.push_back(right);
            for(int j = 1; j < right.size(); j++){
                v2.push_back(right);
                v2.back().insert(j, ".");
            }

            // combine
            for(auto &l : v1){
                if(!isValid(l)) continue;
                for(auto &r : v2){
                    if(!isValid(r)) continue;
                    ans.push_back("(" + l + ", " + r + ")");
                }
            }

            v1.clear();
            v2.clear();
        }

        return ans;
    }
};