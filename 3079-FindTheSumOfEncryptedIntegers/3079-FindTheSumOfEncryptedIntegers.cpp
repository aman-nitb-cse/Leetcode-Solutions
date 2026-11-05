// Last updated: 11/6/2026, 4:47:00 AM
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