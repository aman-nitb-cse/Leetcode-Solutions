// Last updated: 11/6/2026, 4:35:19 AM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> freq(101);

        for(int &i : nums) freq[i]++;

        for(int &i : nums){
            if(!(i & 1) && freq[i] == 1) return i;
        }
        return -1;
    }
};