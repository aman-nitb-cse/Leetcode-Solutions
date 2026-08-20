// Last updated: 8/20/2026, 9:08:02 PM
class SummaryRanges {
public:
    map<int,int> mp;
    
    void addNum(int val) {

        auto it = mp.lower_bound(val);

        // merge both side 
        if(it != mp.end() && it != mp.begin() && it->first == val + 1 && prev(it)->second == val - 1){
            int L = prev(it)->first;
            int R = it->second;

            mp.erase(mp.erase(prev(it)));

            mp[L] = R;
        }
        // merge right
        else if(it != mp.end() && it->first <= val + 1){

            int L = min(val, it->first);
            int R = it->second;

            mp.erase(it);

            mp[L] = R;
        }
        // merge left
        else if(it != mp.begin() && prev(it)->second >= val - 1){
            it--;
            auto [L, R] = *it;

            R = max(R, val);

            mp.erase(it);

            mp[L] = R;
        }
        // no merge
        else {
            mp[val] = val;
        }
    }
    
    vector<vector<int>> getIntervals() {

        vector<vector<int>> ans;

        for(auto& [L, R] : mp) ans.push_back({L, R});

        return ans;
    }
};