// Last updated: 6/25/2026, 11:12:35 PM
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map <int, int> hash;
        for(int i = 0; i <= nums.size() - 2; i++){
            if(nums[i] == key) hash[nums[i + 1]]++;
        }
        int idx = 0, value = nums[0];
        for(auto i : hash){
            if(i.second > idx){
                idx = i.second;
                value = i.first;
            }
        }
        return value;
    }
};