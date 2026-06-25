// Last updated: 6/25/2026, 11:17:08 PM
class Encrypter {
public:
    string val[26] = {""};
    unordered_map<string,int> count;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for(int i = 0; i < keys.size(); i++){
            val[keys[i] - 'a'] = values[i];
        }

        for(string &s : dict) encrypt_count(s);
    }

    void encrypt_count(string &s) {
        string ans = "";
        for(char &c : s){
            if(val[c - 'a'].empty()) return;
            ans += val[c - 'a'];
        }
        count[ans]++;
    }
    
    string encrypt(string s) {
        string ans = "";
        for(char &c : s){
            if(val[c - 'a'].empty()) return "";
            ans += val[c - 'a'];
        }
        return ans;
    }
    
    int decrypt(string s) {
        return count[s];
    }
};