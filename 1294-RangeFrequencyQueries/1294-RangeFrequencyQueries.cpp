// Last updated: 6/25/2026, 11:17:52 PM
class SQRT{
public:

    int n, bs;

    vector<int> nums;
    vector<unordered_map<int,int>> B;

    SQRT(vector<int>& arr) : nums(arr) {

        n = nums.size();

        bs = sqrt(n) + 1;

        B.resize(bs);

        for(int i = 0; i < n; i++) B[i / bs][nums[i]]++;
    }

    int query(int l, int r, int val){

        int f = 0;

        // move l forward

        while(l <= r && l % bs){

            f += (nums[l] == val);

            l++;
        }

        // move r backward

        while(l <= r && (r + 1) % bs){

            f += (nums[r] == val);

            r--;
        }

        // whole blocks

        while(l <= r){

            f += B[l / bs][val];

            l += bs;
        }

        return f;
    }
};

class RangeFreqQuery {
public:
    SQRT* sq;
    RangeFreqQuery(vector<int>& arr) {
        sq = new SQRT(arr);
    }
    
    int query(int left, int right, int value) {
        return sq->query(left, right, value);
    }
};