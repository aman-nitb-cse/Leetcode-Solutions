// Last updated: 6/24/2026, 3:28:05 AM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        vector<long long> v(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(!st.empty() && st.top() == v[i]){
                st.pop();
                v[i] *= 2;
                i--;
            }
            else {
                st.push(v[i]);
            }
        }

        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};