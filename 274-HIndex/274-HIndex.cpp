// Last updated: 8/20/2026, 9:09:50 PM
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();

        ranges::sort(c);

        for(int i = 0; i < n; i++)
            if(c[i] >= n - i) return n - i;
        
        return 0;
    }
};