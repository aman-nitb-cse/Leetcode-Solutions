// Last updated: 6/25/2026, 11:11:09 PM
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector <unordered_set<char>> hash(n);
        // hash[i] == hashing of string w[i]
        for(int i = 0; i < n; i++){
            for(char &c : words[i]) hash[i].insert(c);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(hash[i] == hash[j]) count++;
            }
        }
        return count;
    }
};