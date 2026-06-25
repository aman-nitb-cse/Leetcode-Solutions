// Last updated: 6/25/2026, 11:18:08 PM
class Solution {
public:
    pair<int,int> index(char c){
        int n = c - 'a';
        return {n / 5, n % 5};
    }
    string str(char c, int diff){
        if(diff <= 0) return "";
        return string(diff, c);
    }
    string alphabetBoardPath(string target) {
        string ans = "";
        pair<int,int> prev = {0, 0};
        for(char &ch : target){
            auto curr = index(ch);
            if(ch == 'z'){
                ans += str('R', curr.second - prev.second) + str('L', prev.second - curr.second);
                ans += str('U', prev.first - curr.first) + str('D', curr.first - prev.first);
                ans += '!';
            }
            else {
                ans += str('U', prev.first - curr.first) + str('D', curr.first - prev.first);
                ans += str('R', curr.second - prev.second) + str('L', prev.second - curr.second);
                ans += '!';
            }
            prev = curr;
        }
        return ans;
    }
};