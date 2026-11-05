// Last updated: 11/6/2026, 4:32:41 AM
class Solution {
public:
    using ll = long long;
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

        int cnt = 0;

        for(int i = 0; i < n; i++){
            ll sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];

                ll sum_ = sum;

                if(sum_ % 10 == x){
                    while(sum_ > 9){
                        sum_ /= 10;
                    }
                    if(sum_ == x) cnt++;
                }
            }
        }

        return cnt;
    }
};