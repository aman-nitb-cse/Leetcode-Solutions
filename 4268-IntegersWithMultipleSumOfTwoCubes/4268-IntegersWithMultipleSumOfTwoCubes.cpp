// Last updated: 6/24/2026, 3:27:20 AM
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> mp;
        int limit = cbrt(n);

        for(int a = 1; a <= limit; a++){
            int a3 = a * a * a;
            for(int b = a; b <= limit; b++){
                int x = a3 + b * b * b;
                if(x > n) break;
                mp[x]++;
            }
        }

        vector<int> ans;

        for(auto &p : mp){
            if(p.second >= 2) ans.push_back(p.first);
        }

        ranges::sort(ans);
        return ans;
    }
};