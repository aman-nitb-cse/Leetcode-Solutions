// Last updated: 8/20/2026, 9:07:12 PM
class Solution {
public:
    vector<int> nums, random;
    int n;
    Solution(vector<int>& _nums){
        nums = random = _nums;
        srand(time(0));
        n = nums.size();
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        swap(random[rand() % n], random[rand() % n]);
        return random;
    }
};