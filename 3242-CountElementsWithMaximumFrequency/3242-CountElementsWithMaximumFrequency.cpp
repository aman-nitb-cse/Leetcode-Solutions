// Last updated: 6/24/2026, 3:31:36 AM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int &i : nums) hash[i]++;

        map<int, int> v;

        for(auto i = hash.begin(); i != hash.end(); i++){
            v[i->second]++;
        }

        return v.rbegin()->first * v.rbegin()->second;
    }
};