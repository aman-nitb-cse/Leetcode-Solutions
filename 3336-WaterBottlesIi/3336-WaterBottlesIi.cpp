// Last updated: 6/24/2026, 3:31:09 AM
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