// Last updated: 8/20/2026, 9:05:47 PM
class Solution {
public:
    int compress(vector<char>& s) {
        char curr_char = s.front();
        int curr_count = 1;
        int curr_idx = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i - 1]){
                // store char and freq at curr_idx
                s[curr_idx++] = curr_char;
                if(curr_count != 1){
                    string count = to_string(curr_count);
                    for(char &c : count){
                        s[curr_idx++] = c;
                    }
                }

                // reset values
                curr_char = s[i];
                curr_count = 1;
            }
            else curr_count++;
        }

        // store remaining char and freq
        s[curr_idx++] = curr_char;
        if(curr_count != 1){
            string count = to_string(curr_count);
            for(char &c : count){
                s[curr_idx++] = c;
            }
        }
        return curr_idx;
    }
};