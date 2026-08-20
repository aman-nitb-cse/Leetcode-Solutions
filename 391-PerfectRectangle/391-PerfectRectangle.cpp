// Last updated: 8/20/2026, 9:07:03 PM
class Solution {
public:
    long long area(vector<int>& v){
        return 1LL * (v[2] - v[0]) * (v[3] - v[1]);
    }

    long long key(int x, int y){
        return ( (long long)x << 32 ) | (unsigned int)y;
    }

    bool isRectangleCover(vector<vector<int>>& rec) {
        long long sum = 0;
        vector<int> v = rec[0];

        unordered_set<long long> st;

        for(auto &i : rec){
            sum += area(i);

            v[0] = min(v[0], i[0]);
            v[1] = min(v[1], i[1]);
            v[2] = max(v[2], i[2]);
            v[3] = max(v[3], i[3]);

            for(auto k : {
                key(i[0], i[1]),
                key(i[0], i[3]),
                key(i[2], i[1]),
                key(i[2], i[3])
            }){
                if(st.count(k)) st.erase(k);
                else st.insert(k);
            }
        }

        if(sum != area(v)) return false;

        return st.size() == 4 &&
               st.count(key(v[0], v[1])) &&
               st.count(key(v[0], v[3])) &&
               st.count(key(v[2], v[1])) &&
               st.count(key(v[2], v[3]));
    }
};