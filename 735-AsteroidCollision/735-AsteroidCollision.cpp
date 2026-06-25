// Last updated: 6/25/2026, 11:21:49 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        for(int &i : nums){
            
            while(true){

                if(st.empty() || st.top() * i > 0 || st.top() < 0 || i > 0) {
                    st.push(i);
                    break;
                }

                int sum = st.top() + i;

                if(sum == 0) {
                    st.pop();
                    break;
                }
                else if(sum < 0) st.pop();
                else break;
            }
        }
        nums.clear();

        while(!st.empty()){
            nums.push_back(st.top());
            st.pop();
        }
        ranges::reverse(nums);
        return nums;
    }
};