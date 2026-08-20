// Last updated: 8/20/2026, 9:02:36 PM
class Solution {
public:
    vector<string> findRestaurant(vector<string>& v1, vector<string>& v2) {
        int index_sum = 1e9;
        vector<string> ans;

        for(int i = 0; i < v1.size(); i++){
            for(int j = 0; i + j <= index_sum && j < v2.size(); j++){
                if(v1[i] != v2[j]) continue;
                if(i + j < index_sum){
                    ans.clear();
                    index_sum = i + j;
                }
                ans.push_back(v1[i]);
            }
        }
        return ans;
    }
};