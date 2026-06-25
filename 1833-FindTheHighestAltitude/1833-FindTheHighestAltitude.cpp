// Last updated: 6/25/2026, 11:15:08 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, pref = 0;
        for(int &i : gain){
            pref += i;

            ans = max(ans, pref);
        }
        return ans;
    }
};