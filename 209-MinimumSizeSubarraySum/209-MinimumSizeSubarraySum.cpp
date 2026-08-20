// Last updated: 8/20/2026, 9:11:39 PM
class Solution {
public:
    int minSubArrayLen(int k, vector<int>& v) {
        for(int i = 1; i < v.size(); i++) v[i] += v[i - 1];

        int s = 0, e = 0;
        int mini = INT_MAX;
        while(e < v.size() and s <= e){
            int sum = v[e];
            if(s) sum -= v[s - 1];

            if(sum >= k){
                mini = min(mini, e - s + 1);
                if(mini == 1) return 1;
                s++;
            }
            else e++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};