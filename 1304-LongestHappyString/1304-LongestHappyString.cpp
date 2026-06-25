// Last updated: 6/25/2026, 11:17:45 PM
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a + b + c;
        string s = "";
        vector<pair<int,char>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while(n--){
            // sort
            sort(v.begin(), v.end(),
                [](pair<int,char> a, pair<int,char> b){
                    return a.first > b.first;
                }
            );
            if(s.size() < 2 || s.back() != v[0].second || *(s.rbegin() + 1) != v[0].second){
                if(v[0].first == 0) return s;
                v[0].first--;
                s += v[0].second;
            }
            else {
                if(v[1].first == 0) return s;
                v[1].first--;
                s += v[1].second;
            }
        }
        return s;
    }
};