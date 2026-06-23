// Last updated: 6/24/2026, 3:27:23 AM
class Solution {
public:
    vector<double> internalAngles(vector<int>& s) {
        int a = s[0], b = s[1], c = s[2];

        if(a + b <= c || b + c <= a || a + c <= b) return {};

        vector<double> ans;

        auto calc = [&](double x){
            return acos(x) * 180.0 / M_PI;
        };

        ans.push_back(calc((b * b + c * c - a * a) / (2.0 * b * c)));
        ans.push_back(calc((a * a + c * c - b * b) / (2.0 * a * c)));
        ans.push_back(calc((b * b + a * a - c * c) / (2.0 * b * a)));

        ranges::sort(ans);
        return ans;
    }
};