// Last updated: 6/24/2026, 3:30:13 AM
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