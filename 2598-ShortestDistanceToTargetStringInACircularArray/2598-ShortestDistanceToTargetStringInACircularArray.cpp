// Last updated: 6/25/2026, 11:11:04 PM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int s) {
        int n = words.size();
        int ans = 1e9;

        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int d = abs(i - s);
                ans = min(ans, min(d, n - d));
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};