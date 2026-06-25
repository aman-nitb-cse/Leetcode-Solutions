// Last updated: 6/25/2026, 11:21:33 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int idx[26] = {-1};
        vector<int> ans;

        for(int i = 0; i < n; i++){
            idx[s[i] - 'a'] = max(idx[s[i] - 'a'], i);
        }
        
        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            end = max(end, idx[s[i] - 'a']);

            if(end == i){
                ans.push_back(end - start + 1);
                start = end = i + 1;
            }
        }
        return ans;
    }
};