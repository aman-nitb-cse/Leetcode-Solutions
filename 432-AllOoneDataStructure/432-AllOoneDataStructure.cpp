// Last updated: 8/20/2026, 9:06:05 PM
class AllOne {
public:
    map<int, unordered_set<string>> mp;
    unordered_map<string,int> count;
    void inc(string key) {
        if(!count.count(key)){
            count[key] = 0;
            mp[0].insert(key);
        }

        int& c = count[key];
        mp[c].erase(key);
        if(mp[c].empty()) mp.erase(c);
        mp[++c].insert(key);
    }
    
    void dec(string key) {
        int& c = count[key];
        mp[c].erase(key);
        if(mp[c].empty()) mp.erase(c);
        if(c == 1) {
            count.erase(key);
            return;
        }
        mp[--c].insert(key);
    }
    
    string getMaxKey() {
        if(mp.empty()) return "";
        return *mp.rbegin()->second.begin();
    }
    
    string getMinKey() {
        if(mp.empty()) return "";
        return *mp.begin()->second.begin();
    }
};