// Last updated: 11/6/2026, 4:34:07 AM
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(auto &s : events){
            if(s == "W") counter++;
            else if(s == "WD" || s == "NB") score++;
            else score += s[0] - '0';

            if(counter == 10) break;
        }
        return {score, counter};
    }
};