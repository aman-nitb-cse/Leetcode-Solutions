// Last updated: 11/6/2026, 5:00:55 AM
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map <int, int, greater<int>> hash;
        for(int &i : nums) hash[i]++;

        multimap <int, int> temp;
        for(auto &i : hash) temp.insert({i.second, i.first});

        nums.clear();
        for(auto i = temp.begin(); i != temp.end(); i++){
            int t = i->first;
            while(t--) nums.push_back(i->second);
        }
        return nums;
    }
};