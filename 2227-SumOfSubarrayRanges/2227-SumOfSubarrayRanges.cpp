// Last updated: 6/25/2026, 11:13:01 PM
class Solution {
public:
    long long maxSum(vector<int>& v, long long s, long long e){
        long long size = v.size();
        if(e >= size or s > e) return 0;
        if(s == e) return v[s];
        long long max_index = s;
        for(long long i = s; i <= e; i++){
            if(v[max_index] < v[i]) max_index = i;
        }
        return v[max_index] * (max_index - s + 1) * (e - max_index + 1) + maxSum(v, s, max_index - 1) + maxSum(v, max_index + 1, e);
    }

    long long minSum(vector<int>& v, long long s, long long e){
        long long size = v.size();
        if(e >= size or s > e) return 0;
        if(s == e) return v[s];
        long long min_index = s;
        for(long long i = s; i <= e; i++){
            if(v[min_index] > v[i]) min_index = i;
        }
        return v[min_index] * (min_index - s + 1) * (e - min_index + 1) + minSum(v, s, min_index - 1) + minSum(v, min_index + 1, e);
    }

    long long subArrayRanges(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1) - minSum(nums, 0, nums.size() - 1);
    }
};