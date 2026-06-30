// Last updated: 6/30/2026, 2:13:08 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int &i : nums) freq[i]++;

        int ans = 0;
        int root = sqrt(1e9);

        for(auto&& [val, f] : freq){
            int cnt = 0;
            int x = val;
            if(x == 1) continue;
            while(x != 1 && freq.count(x) && freq[x] >= 2 && x < root) {
                x *= x;
                cnt += 2;
            }
            if(freq.count(x)) cnt++;
            else cnt--;

            ans = max(ans, cnt);
        } 

        // handle one
        int f = freq[1];
        ans = max(ans, f - !(f & 1));

        return ans;
    }
};