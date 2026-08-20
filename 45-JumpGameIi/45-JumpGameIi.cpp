// Last updated: 8/20/2026, 9:18:13 PM
class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;

        int cur = 0;
        int far = 0;

        for(int i = 0; i < nums.size() - 1; i++){

            far = max(far, i + nums[i]);

            if(i == cur){

                jumps++;

                cur = far;
            }
        }

        return jumps;
    }
};