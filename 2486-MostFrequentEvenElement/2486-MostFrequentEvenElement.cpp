// Last updated: 6/25/2026, 11:11:45 PM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map <int, int> hash;
        for(int &i : nums){
            if(!(i&1)) hash[i]++;
        }
        int max_freq = 0;
        int min_even = -1;
        for(auto i : hash){
            if(i.second > max_freq){
                min_even = i.first;
                max_freq = i.second;
            }
            else if(i.second == max_freq and min_even > i.first){
                min_even = i.first;
            }
        }
        return min_even;
    }
};