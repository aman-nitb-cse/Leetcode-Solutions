// Last updated: 6/30/2026, 2:16:59 PM
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        ranges::sort(coins);

        int e = 0;

        for(int &i : coins){
            if(i > e + 1) break;
            e += i;
        }

        return e + 1;
    }
};