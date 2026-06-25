// Last updated: 6/25/2026, 11:37:24 PM
class MapSum {
public:
    unordered_map<string,int> mp;
    unordered_map<string,int> prefix;
    void insert(string key, int val) {
        int diff = val - mp[key];
        mp[key] = val;

        while(!key.empty()){
            prefix[key] += diff;
            key.pop_back();
        }
    }
    
    int sum(string p) {
        return prefix[p];
    }
};