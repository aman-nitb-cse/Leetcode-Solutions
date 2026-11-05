// Last updated: 11/6/2026, 4:59:44 AM
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