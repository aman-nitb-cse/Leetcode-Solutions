// Last updated: 6/25/2026, 11:12:24 PM
class CountIntervals {
public:
    map<int,int> mp; // [L, R]
    int cnt = 0;

    void add(int L, int R) {

        auto it = mp.lower_bound(L);

        if(it != mp.begin() && prev(it)->second >= L - 1) it--;

        while(it != mp.end() && it->first <= R + 1){

            cnt -= it->second - it->first + 1;

            L = min(L, it->first);
            R = max(R, it->second);

            it = mp.erase(it);
        }

        mp[L] = R;

        cnt += R - L + 1;
    }

    int count() {
        return cnt;
    }
};