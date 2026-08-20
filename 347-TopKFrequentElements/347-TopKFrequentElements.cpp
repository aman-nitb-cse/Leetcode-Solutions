// Last updated: 8/20/2026, 9:08:05 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map <int,int> hash;
        for(int &i : nums) hash[i]++;
        multimap <int,int> temp;
        for(auto &i : hash) temp.insert({i.second, i.first});
        nums.clear();
        for(auto i = temp.rbegin(); k; i++, k--) nums.push_back(i->second);
        return nums;
    }
};