// Last updated: 6/25/2026, 11:15:39 PM
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++) arr[i] += arr[i - 1];
        int sum = 0;
        for(int i = 1; i <= arr.size(); i += 2){
            for(int j = 0; j <= arr.size() - i; j++){
                if(!j) sum += arr[i - 1];
                else sum += arr[j + i - 1] - arr[j - 1];
            }
        }
        return sum;
    }
};