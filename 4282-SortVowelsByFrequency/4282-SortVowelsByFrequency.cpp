// Last updated: 6/24/2026, 3:27:06 AM
class Solution {
public:
    bool isVowel(char &c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        unordered_map<char, pair<int,int>> freq; // {freq, first pos}

        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])) {
                if(!freq.count(s[i])) freq[s[i]] = {1, i};
                else freq[s[i]].first++;
            }
        }

        priority_queue<array<int, 4>> pq; // {total_freq, - idx, char, rem freq}
        for(auto &[c, p] : freq){
            pq.push({p.first, -p.second, c, p.first});
        }

        for(char &c : s){
            if(isVowel(c)) {
                auto [f, i, ch, rem] = pq.top(); pq.pop();
                if(rem != 1) pq.push({f, i, ch, rem - 1});
                c = ch;
            }
        }
        return s;
    }
};