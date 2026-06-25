// Last updated: 6/25/2026, 11:15:06 PM
// copy paste
class Solution {
public:
    class DSU {
    public:
        vector<int> p, sz;
        DSU(int n){
            p.resize(n);
            sz.assign(n,1);
            for(int i = 0; i < n; i++) p[i] = i;
        }
        int find(int x){
            return p[x] == x ? x : p[x] = find(p[x]);
        }
        void unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a == b) return;
            if(sz[a] < sz[b]) swap(a,b);
            p[b] = a;
            sz[a] += sz[b];
        }
    };

    int minimumHammingDistance(vector<int>& s, vector<int>& t, vector<vector<int>>& sw) {
        int n = s.size();
        DSU d(n);

        // 1. build components
        for(auto &e : sw) d.unite(e[0], e[1]);

        // 2. group indices by parent
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[d.find(i)].push_back(i);

        int ans = 0;

        // 3. process each component
        for(auto &[_, idxs] : mp){
            unordered_map<int,int> cnt;

            // count source values
            for(int i : idxs) cnt[s[i]]++;

            // match with target
            for(int i : idxs){
                if(cnt[t[i]] > 0) cnt[t[i]]--;
                else ans++;
            }
        }

        return ans;
    }
};