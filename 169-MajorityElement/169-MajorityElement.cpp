// Last updated: 8/20/2026, 9:12:35 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> hash;
        for(int i : nums) hash[i]++;

        for(auto i : hash){
            if(i.second > n/2) return i.first;
        }
        return 0;
    }
};