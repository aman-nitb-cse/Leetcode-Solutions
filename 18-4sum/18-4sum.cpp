// Last updated: 8/20/2026, 9:19:39 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        set<vector<int>> st;
        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                int s = j + 1, e = v.size() - 1;
                while(s < e){
                    long long sum = 0LL + v[i] + v[j] + v[s] + v[e];

                    if(sum == target) st.insert({v[i], v[j], v[s++], v[e--]});
                    else if(sum > target) e--;
                    else s++;
                }
            }
        }


        return vector<vector<int>> (st.begin(), st.end());
    }
};