// Last updated: 11/6/2026, 4:58:48 AM
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