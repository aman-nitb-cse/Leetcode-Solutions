// Last updated: 6/25/2026, 11:12:12 PM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);

        for(int &i : spells){
            double target = success * 1.0 / i;

            i = potions.end() - ranges::lower_bound(potions, target);
        }
        return spells;
    }
};