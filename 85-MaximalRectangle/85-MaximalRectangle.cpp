// Last updated: 8/20/2026, 9:16:14 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        stack<pair<int,int>> st; // {height, width(compressed)}
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
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int> h(mat[0].size());
        int ans = 0;
        for(auto &v : mat){
            for(int i = 0; i < v.size(); i++){
                if(v[i] == '1') h[i]++;
                else h[i] = 0;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};