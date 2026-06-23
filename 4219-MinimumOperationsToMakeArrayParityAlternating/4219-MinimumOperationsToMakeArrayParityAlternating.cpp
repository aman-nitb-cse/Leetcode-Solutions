// Last updated: 6/24/2026, 3:27:58 AM
class Solution {
public:
    int maxi, mini;
    vector<int> solve(vector<int> nums, bool pp){
        int op = 0;
        int M = INT_MIN;
        int m = INT_MAX;
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++, pp = !pp){
            if((nums[i] & 1) == pp){ // change
                int inc = nums[i] + 1;
                int dec = nums[i] - 1;

                if(inc < maxi || dec < mini){
                    M = max(inc, M);
                    m = min(inc, m);
                }
                else if(dec > mini || inc > maxi){
                    M = max(dec, M);
                    m = min(dec, m);
                }
                else v.push_back({dec, inc});

                op++;
            }
            else {
                M = max(nums[i], M);
                m = min(nums[i], m);
            }
        }

        for(auto &p : v){
            // take first
            int M1 = max(p.first, M);
            int m1 = min(p.first, m);

            // take second
            int M2 = max(p.second, M);
            int m2 = min(p.second, m);

            if(M1 - m1 < M2 - m2) {
                M = M1;
                m = m1;
            }
            else {
                M = M2;
                m = m2;
            }
        }

        return {op, M - m};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        maxi = *max_element(nums.begin(), nums.end());
        mini = *min_element(nums.begin(), nums.end());
        auto a1 = solve(nums, true);
        auto a2 = solve(nums, false);
        if(a2[0] < a1[0] || (a1[0] == a2[0] && a2[1] < a1[1])) return a2;
        return a1;
    }
};