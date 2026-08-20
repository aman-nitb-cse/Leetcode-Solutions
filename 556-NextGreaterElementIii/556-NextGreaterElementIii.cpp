// Last updated: 8/20/2026, 9:03:02 PM
class Solution {
public:
    int nextGreaterElement(int n) {
        auto s = to_string(n);
        for(int i = s.size() - 1; i; i--){
            if(s[i] > s[i - 1]) {
                auto it = upper_bound(s.rbegin(), s.rend() - i, s[i - 1]);
                swap(s[i - 1], *it);
                sort(s.begin() + i, s.end());
                long long ans = stoll(s);
                return ans > INT_MAX ? -1 : ans;
            }
        }
        return -1;
    }
};