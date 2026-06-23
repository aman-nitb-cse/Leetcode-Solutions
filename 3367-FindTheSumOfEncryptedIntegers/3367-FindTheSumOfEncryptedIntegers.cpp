// Last updated: 6/24/2026, 3:31:06 AM
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int &i : nums){
            string s = to_string(i);
            int maxi = *ranges::max_element(s);
            int n = s.size();
            ans += stoi(string(n, maxi));
        }
        return ans;
    }
};