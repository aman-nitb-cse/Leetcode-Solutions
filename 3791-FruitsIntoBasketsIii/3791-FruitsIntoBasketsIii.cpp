// Last updated: 6/24/2026, 3:29:52 AM
class SQRT{
public:

    int n, bs, blocks;

    vector<int> nums, B;

    SQRT(vector<int>& arr) : nums(arr) {

        n = nums.size();

        bs = sqrt(n);

        blocks = (n + bs - 1) / bs;

        B.resize(blocks); // store maximum of the block

        for(int i = 0; i < n; i++) B[i / bs] = max(B[i / bs], nums[i]);
    }

    bool query(int x){
        for(int b = 0; b < blocks; b++){
            if(B[b] >= x){
                // found
                B[b] = 0;
                for(int i = bs * b; i < min(n, (b + 1) * bs); i++){
                    if(nums[i] >= x){
                        nums[i] = 0;
                        x = INT_MAX;
                    }
                    else B[b] = max(B[b], nums[i]);
                }

                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& F, vector<int>& B) {

        SQRT sq(B);

        int n = F.size(), cnt = 0;

        for(int &i : F){
            if(!sq.query(i)) cnt++;
        }

        return cnt;
    }
};