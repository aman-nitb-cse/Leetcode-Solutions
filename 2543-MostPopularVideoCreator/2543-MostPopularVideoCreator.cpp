// Last updated: 6/25/2026, 11:11:28 PM
class Solution {
public:
    struct node {
        string ID = "";
        long long total_views = 0, curr_views = -1;
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {

        unordered_map<string, node> mp;

        long long max_views = 0;

        for(auto&& [c, id, v] : views::zip(creators, ids, views)){
            auto& x = mp[c];

            x.total_views += v;
            if(v > x.curr_views || (v == x.curr_views && id < x.ID)){
                x.ID = id;
                x.curr_views = v;
            }

            max_views = max(max_views, x.total_views);
        }


        vector<vector<string>> ans;

        for(auto &[c, x] : mp){
            if(x.total_views == max_views){
                ans.push_back({c, x.ID});
            }
        }

        return ans;
    }
};