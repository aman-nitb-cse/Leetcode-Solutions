// Last updated: 11/6/2026, 4:31:25 AM
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;

        int p = (1 << 25);

        for(int &i : nums){
            int z = i / p;
            int rem = i % p;

            string s;

            for(int j = 0; j < z; j++) s += 'z';


            // cout << s << endl;

            for(int j = 24; j >= 0; j--){
                if((rem >> j) & 1){
                    s += (char) ('a' + j);
                }
                // cout << s << endl;
            }

            ans.push_back(s);
        }
        return ans;
    }
};