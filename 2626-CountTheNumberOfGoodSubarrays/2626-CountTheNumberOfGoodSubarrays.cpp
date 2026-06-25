// Last updated: 6/25/2026, 11:10:59 PM
class Solution {
public:
    unordered_map<int, int> hash;
    long long k, pairs = 0;
    void add(int x){
        hash[x]++;
        pairs += hash[x] - 1;
    }
    void remove(int x){
        hash[x]--;
        pairs -= hash[x];
    }

    long long countGood(vector<int>& v, int _k) {
        k = _k;
        vector<pair<int, int>> st;
        long long count = 0, i = 0, j = -1, size = v.size();
        while (j < size) {
            if (pairs >= k) {
                if (!st.empty() && st.back().second == j)
                    st.back().first = i;
                else
                    st.push_back({i, j});
                remove(v[i]);
                i++;
            } else {
                j++;
                if(j < v.size()) add(v[j]);
            }
        }
        for (i = 0; i < st.size(); i++) {
            long long m = st[i].first, n;
            if (i + 1 == st.size())
                n = v.size() - st[i].second - 1;
            else
                n = st[i + 1].second - st[i].second - 1;
            count += (m + 1) * (n + 1);
        }
        return count;
    }
};