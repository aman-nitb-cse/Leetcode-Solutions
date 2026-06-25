// Last updated: 6/25/2026, 11:13:31 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>a;
        int rem = grid[0][0] % x;

        for(auto &v : grid){
            for(int& i : v){
                if(i % x != rem) return -1;
                a.push_back(i / x);
            }
        }

        ranges::sort(a);
        int med=a[a.size()/2];

        int ans = 0;
        for(int& i : a) ans+=abs(i - med);
        return ans;
    }
};