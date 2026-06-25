// Last updated: 6/25/2026, 11:10:42 PM
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        unordered_map<int,vector<int>> m;
        for(int i = 0; i < q.size(); i++) m[q[i]].push_back(i);

        long long big_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int big_count = nums.size();

        long long small_sum = 0;
        int small_count = 0;

        vector<long long> ans(q.size());

        unordered_map<int,int> st;
        for(int x : nums) st[x]++;

        nums.insert(nums.end(), q.begin(), q.end());
        ranges::sort(nums);

        for(int &i : nums){
            bool is_num = st[i] > 0;

            if(is_num){
                st[i]--;
                big_count--;
                big_sum -= i;
            }

            if(m.count(i)){
                long long val = big_sum - small_sum + 1LL*(small_count - big_count)*i;
                for(int idx : m[i])
                    ans[idx] = val;
            }

            if(is_num){
                small_count++;
                small_sum += i;
            }
        }

        return ans;
    }
};