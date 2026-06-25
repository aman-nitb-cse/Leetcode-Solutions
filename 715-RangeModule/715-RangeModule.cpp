// Last updated: 6/25/2026, 11:37:01 PM
class RangeModule {
public:
    map<int,int> mp; // [L, R]

    void addRange(int L, int R) {

        R--;

        auto it = mp.lower_bound(L);

        if(it != mp.begin() && prev(it)->second >= L - 1) it--;

        while(it != mp.end() && it->first <= R + 1){

            L = min(L, it->first);
            R = max(R, it->second);

            it = mp.erase(it);
        }

        mp[L] = R;
    }

    bool queryRange(int L, int R) {

        auto it = mp.upper_bound(L);

        return it != mp.begin() && prev(it)->second >= R - 1;
    }

    void removeRange(int L, int R) {

        R--;

        auto it = mp.upper_bound(L);

        if(it != mp.begin()) it--;

        vector<pair<int,int>> add;

        while(it != mp.end() && it->first <= R){

            auto [l, r] = *it;

            if(r < L){
                ++it;
                continue;
            }

            if(l < L) add.push_back({l, L - 1});

            if(R < r) add.push_back({R + 1, r});

            mp.erase(it++);
        }
        mp.insert(add.begin(), add.end());
    }
};