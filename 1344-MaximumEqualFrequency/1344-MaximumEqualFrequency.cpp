// Last updated: 8/20/2026, 8:54:10 PM
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> f; // value -> freq
        unordered_map<int,int> ff; // freq of freq

        for(int &i : nums) f[i]++;

        for(auto &&[_, F] : f) {
            ff[F]++;
        }
        int n = nums.size();

        for(int i = n - 1; i > 0; i--){

            // check
            if(ff.size() == 2){
                auto [f1, ff1] = *ff.begin();
                auto [f2, ff2] = *next(ff.begin());

                if((f1 - 1 == f2 || f1 == 1) && ff1 == 1) return i + 1;
                if((f2 - 1 == f1 || f2 == 1) && ff2 == 1) return i + 1;
            }
            else if(ff.size() == 1) {

                if(ff.begin()->first == 1) return i + 1;
                if(ff.begin()->second == 1) return i + 1;
            }

            // update
            int of = f[nums[i]];
            int nf = --f[nums[i]];

            ff[of]--;

            if(ff[of] == 0) ff.erase(of);

            if(nf) ff[nf]++;
        }

        return 1;
    }
};