// Last updated: 6/24/2026, 3:27:57 AM
class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 2 && s[0] > s[1]) return -1;
        if(ranges::is_sorted(s)) return 0;

        auto [small, big] = ranges::minmax_element(s);

        int min_count = 0;
        int max_count = 0;

        for(char &c : s){
            if(c == *big) max_count++;
            if(c == *small) min_count++;
        }
        
        if(s.back() == *big || s.front() == *small) return 1;
        if(s.front() == *big && s.back() == *small && max_count == 1 && min_count == 1) return 3;
        return 2;
    }
};