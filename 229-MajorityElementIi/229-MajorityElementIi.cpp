// Last updated: 8/20/2026, 9:10:53 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> hash;
        for(int &i : nums) hash[i]++;
        
        nums.clear();
        for(auto i : hash){
            if(i.second > n/3) nums.push_back(i.first); 
        }
        return nums;
    }
};