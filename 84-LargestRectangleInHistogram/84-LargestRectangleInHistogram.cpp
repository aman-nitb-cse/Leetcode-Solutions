// Last updated: 8/20/2026, 9:16:12 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        // h, w
        stack<pair<int,int>> st;
        int ans = 0;
        auto calc = [&](int h){
            int w = 0;
            while(!st.empty() && h < st.top().first){
                w += st.top().second;
                ans = max(ans, w * st.top().first);
                st.pop();
            }
            st.push({h, w + 1});
        };

        for(int &i : H) calc(i);
        calc(0);
        return ans;
    }
};