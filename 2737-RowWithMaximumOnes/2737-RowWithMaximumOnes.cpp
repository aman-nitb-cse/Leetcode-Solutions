// Last updated: 6/24/2026, 3:32:31 AM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ones = 0;
        int idx = 0; 

        for(auto [i, v] : views::enumerate(mat)){
            int sum = accumulate(v.begin(), v.end(), 0);

            if(sum > ones){
                ones = sum;
                idx = i;
            }
        }

        return {idx, ones};
    }
};