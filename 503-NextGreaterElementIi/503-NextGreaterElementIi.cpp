// Last updated: 8/20/2026, 9:04:05 PM
class Solution {
public:
    int n;
    int dec(int i){
        return i ? i - 1 : n - 1;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        // find maxi index
        int maxi = 0;
        n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[maxi]) maxi = i;
        }

        stack<int> st;
        st.push(nums[maxi]);
        int max_val = nums[maxi];
        nums[maxi] = -1;
        for(int i = dec(maxi); i != maxi; i = dec(i)){
            if(nums[i] == max_val){
                st.push(nums[i]);
                nums[i] = -1;
                continue;
            }
            while(st.top() <= nums[i]) st.pop();

            
            
            int num = nums[i];
            nums[i] = st.top();
            st.push(num);
            
        }

        return nums;
    }
};