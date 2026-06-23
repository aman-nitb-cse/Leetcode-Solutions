// Last updated: 6/24/2026, 3:27:31 AM
class Solution {
public:
    bool check(vector<int>& nums, int k){
        int prev_max = 0;
        for(int i = 0; i < nums.size(); i += k){
            int mini = i;
            bool found = false;
            int curr_max = nums[i];
            for(int j = i; j < i + k; j++){
                if(nums[j] < prev_max) return false;
                if(j != i + k - 1 && nums[j] > nums[j + 1]) {
                    if(found) return false;
                    found = true;
                    mini = j + 1;
                }
                curr_max = max(curr_max, nums[j]);
            }
            prev_max = curr_max;

            int prev = nums[mini];
            for(int j = mini + 1; j < i + k; j++){
                if(nums[j] < prev) return false;
                prev = nums[j];
            }
            for(int j = i; j < mini; j++){
                if(nums[j] < prev) return false;
                prev = nums[j];
            }
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 1; i * i <= n; i++){
            if(n % i) continue;
            if(check(nums, i)) sum += i;
            if(i * i != n && check(nums, n / i)) sum += n / i;
        }
        return sum;
    }
};