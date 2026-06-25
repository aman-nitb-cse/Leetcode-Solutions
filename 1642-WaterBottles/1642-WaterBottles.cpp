// Last updated: 6/25/2026, 11:15:53 PM
class Solution {
public:
    int numWaterBottles(int b, int e) {
        int sum = b;
        int empty_bottle = b;
        while(empty_bottle / e){
            sum += empty_bottle / e;
            empty_bottle = empty_bottle / e + empty_bottle % e;
        }
        return sum;
    }
};