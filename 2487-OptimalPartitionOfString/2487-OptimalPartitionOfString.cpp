// Last updated: 6/25/2026, 11:11:43 PM
class Solution {
public:
    int partitionString(string s) {
        bitset<26> flag;
        int count = 1;
        for(auto &c : s){
            int idx = c - 'a';
            if(flag[idx]){
                count++;
                flag.reset();
            }
            flag.set(idx);
        }
        return count;
    }
};