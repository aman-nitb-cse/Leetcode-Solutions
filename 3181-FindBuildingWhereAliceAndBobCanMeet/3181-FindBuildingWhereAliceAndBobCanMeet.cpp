// Last updated: 6/24/2026, 3:31:48 AM
class SQRT{
public:

    int n, bs;

    vector<int> nums, B;

    SQRT(vector<int>& arr) : nums(arr){

        n = nums.size();

        bs = sqrt(n) + 1;

        B.resize(bs, INT_MIN);

        for(int i = 0; i < n; i++) B[i / bs] = max(B[i / bs], nums[i]);
    }

    int query(int l, int r, int x){

        while(l <= r){

            // partial block

            if(l % bs){

                if(nums[l] > x) return l;

                l++;

                continue;
            }

            // whole block exists

            if(l + bs - 1 <= r){

                // skip whole block

                if(B[l / bs] <= x){

                    l += bs;

                    continue;
                }

                // search inside block

                for(int i = l; i < l + bs; i++){

                    if(nums[i] > x) return i;
                }

                l += bs;
            }

            // remaining elements

            else{

                if(nums[l] > x) return l;

                l++;
            }
        }

        return -1;
    }
};

class Solution {
public:

    vector<int> leftmostBuildingQueries(vector<int>& nums, vector<vector<int>>& queries) {

        SQRT sq(nums);

        vector<int> ans;

        for(auto &q : queries){

            int a = q[0];
            int b = q[1];

            if(a > b) swap(a,b);

            if(a == b || nums[b] > nums[a]) ans.push_back(b);
            
            else ans.push_back(sq.query(b + 1, nums.size() - 1, nums[a]));
        }

        return ans;
    }
};