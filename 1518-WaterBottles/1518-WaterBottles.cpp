// Last updated: 11/6/2026, 5:01:52 AM
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