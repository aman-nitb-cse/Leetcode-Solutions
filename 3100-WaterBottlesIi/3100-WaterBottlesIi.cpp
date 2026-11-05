// Last updated: 11/6/2026, 4:47:10 AM
class Solution {
public:
    int maxBottlesDrunk(int b, int e) {
        int sum = b;
        int empty = b;
        while(empty / e){
            empty -= e - 1;
            sum++;
            e++;
        }
        return sum;
    }
};