// Last updated: 8/20/2026, 9:05:12 PM
class Solution {
public:
    int poorPigs(int b, int die, int t) {
        int states = t / die + 1;
        int ans = 0;

        for(int curr = 1; curr < b; curr *= states, ans++);
        return ans;
    }
};