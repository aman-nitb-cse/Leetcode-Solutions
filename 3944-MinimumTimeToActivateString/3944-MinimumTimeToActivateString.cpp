// Last updated: 6/24/2026, 3:29:29 AM
class Solution {
public:
    set<int> stars;
    int get_left(int k){
        return *prev(stars.lower_bound(k));
    }
    int get_right(int k){
        return *stars.upper_bound(k);
    }
    int minTime(string s, vector<int>& order, int k) {
        stars = {-1, (int)s.size()};
        long long valids = 0;
        for(int i = 0; i < order.size(); i++){
            stars.insert(order[i]);
            int left = get_left(order[i]);
            int right = get_right(order[i]);

            valids += 1LL * (order[i] - left) * (right - order[i]);
            if(valids >= k) return i;
        }
        return -1;
    }
};