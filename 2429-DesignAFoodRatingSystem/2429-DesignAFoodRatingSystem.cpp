// Last updated: 6/25/2026, 11:12:01 PM
class FoodRatings {
public:
    unordered_map<string, pair<int,string>> cat; // food -> {-rating, categry}
    unordered_map<string, set<pair<int,string>>> mp; // cat -> {-rating, food}
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for(auto&& [f, c, r] : views::zip(foods, cuisines, ratings)){
            cat[f] = {-r, c};
            mp[c].insert({-r, f});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[r, c] = cat[food];

        mp[c].erase({r, food});
        r = - newRating;
        mp[c].insert({r, food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};