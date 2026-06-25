// Last updated: 6/25/2026, 11:17:34 PM
class Solution {
public:
    bool isAnagram(string a, string b){
        multiset<char> A(a.begin(), a.end());
        multiset<char> B(b.begin(), b.end());

        return A == B;
    }
    vector<string> removeAnagrams(vector<string>& w) {
        vector<string> v = {w[0]};
        for(int i = 1; i < w.size(); i++){
            if(!isAnagram(v.back(), w[i])) v.push_back(w[i]);
        }
        return v;
    }
};