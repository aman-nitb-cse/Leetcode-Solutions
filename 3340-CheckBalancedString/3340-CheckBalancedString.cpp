// Last updated: 11/6/2026, 4:44:08 AM
class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        for(int i = 0; i < num.size(); i++){
            if(i&1) sum += num[i] - '0';
            else sum -= num[i] - '0';
        }
        return !sum;
    }
};