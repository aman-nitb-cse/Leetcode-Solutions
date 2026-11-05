// Last updated: 11/6/2026, 4:46:19 AM
class Solution {
public:
    static int numberOfSpecialChars(string& word) {
        bitset<26> A[2];
        for(char c: word){
            A[c > 'Z'].set(c > 'Z' ? c - 'a' : c - 'A');
        }
        return (A[0] & A[1]).count();
    }
};