// Last updated: 6/25/2026, 11:19:17 PM
class TimeMap {
public:
    unordered_map<string,vector<pair<int, string>>> M;
    void set(string key, string value, int ts) {
        M[key].push_back({ts ,value});
    }
    
    string get(string key, int target) {
        
        // Binary Search
        int s = 0, e = M[key].size() - 1;

        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(M[key][mid].first == target) return M[key][mid].second;
            if(M[key][mid].first > target) e = mid - 1;
            else {
                ans = mid;
                s = mid + 1;
            }
        }

        if(ans == -1) return "";
        return M[key][ans].second;
    }
};