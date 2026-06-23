// Last updated: 6/24/2026, 3:28:49 AM
class Solution {
public:
    using ull = unsigned long long;
    bool check(int k, vector<int>& nums){
        unordered_map<ull, int> hash;
        const ull base = 131;
        ull h = 0, pw = 1;

        for(int i = 0; i < k; i++){
            h = h * base + nums[i] + 1;
            pw *= base;
        }
        hash[h]++;

        for(int i = k; i < nums.size(); i++){
            h = h * base + nums[i] + 1;
            h -= pw * (nums[i - k] + 1);
            hash[h]++;
        }

        for(auto&& [s, f] : hash){
            if(f == 1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int s = 1, e = nums.size(), n = nums.size();
        int ans;
        while(s <= e){
            int mid = (s + e) / 2;
            if(check(mid, nums)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};