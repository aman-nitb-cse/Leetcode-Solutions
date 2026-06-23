// Last updated: 6/24/2026, 3:28:37 AM
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& t) {
        set<vector<int>> st(points.begin(), points.end());
        for(int g = 0; ;g++){
            if(g){
                set<vector<int>> add;
                for(auto i = st.begin(); i != st.end(); i++){
                    for(auto j = next(i); j != st.end(); j++){
                        auto a = *i;
                        auto b = *j;
                        for(int k = 0; k < 3; k++) {
                            a[k] += b[k];
                            a[k] /= 2;
                        }

                        if(!st.count(a)) add.insert(a);
                    }
                }
                if(add.empty()) return -1;
                for(auto &a : add) st.insert(a);
            }
            
            if(st.count(t)) return g;
        }
        return -1;
    }
};