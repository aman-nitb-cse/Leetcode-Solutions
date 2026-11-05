// Last updated: 11/6/2026, 4:35:32 AM
class Solution {
public:
    int minimumIndex(vector<int>& c, int x) {
        set<int> s(c.begin(), c.end());

        auto it = s.lower_bound(x);

        if(it == s.end()) return -1;

        for(int i = 0; i < c.size(); i++){
            if(c[i] == *it) return i;
        }
        return -1;
    }
};