// Last updated: 8/20/2026, 9:12:27 PM
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        for(int &x : nums){
            v.push_back(to_string(x));
        }

        ranges::sort(v,
            [](auto &a, auto &b){
                return a + b > b + a;
            }
        );

        string ans = "";
        for(auto &s : v){
            ans += s;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};