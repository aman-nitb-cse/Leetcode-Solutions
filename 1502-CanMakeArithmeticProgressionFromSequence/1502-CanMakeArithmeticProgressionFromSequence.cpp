// Last updated: 7/8/2026, 1:02:31 AM
1class Solution {
2public:
3    bool canMakeArithmeticProgression(vector<int>& arr) {
4        sort(arr.begin(), arr.end());
5
6        int d = arr[1] - arr[0];
7
8        for(int i = 1; i < arr.size(); i++){
9            if(arr[i] - arr[i - 1] != d) return false;
10        }
11
12        return true;
13    }
14};