// Last updated: 6/24/2026, 3:32:15 AM
class Solution {
public:
    string join(string a, string b){
        if(a.find(b) != string::npos) return a;
        if(b.find(a) != string::npos) return b;
        
        int m = a.size(), n = b.size();
        int i;
        for(i = max(m - n, 0); i < m; i++){
            if(a.substr(i) == b.substr(0, m - i)) break;
        }
        return a.substr(0, i) + b;
    }
    string minimumString(string a, string b, string c) {
        vector<string> v;
        v.push_back(join(join(a, b), c));
        v.push_back(join(join(a, c), b));
        v.push_back(join(join(b, a), c));
        v.push_back(join(join(b, c), a));
        v.push_back(join(join(c, a), b));
        v.push_back(join(join(c, b), a));

        ranges::sort(v, 
            [](auto &a, auto &b){
                if(a.size() == b.size()) return a < b;
                return a.size() < b.size();
            }
        );
        return v.front();
    }
};