// Last updated: 6/24/2026, 3:27:49 AM
class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int freq[101] = {0};

        for(int &i : nums){
            freq[i]++;
        }

        for(int i = 1; i <= 100; i++){
            for(int j = i + 1; freq[i] && j <= 100; j++){
                if(freq[i] != freq[j] && freq[j]) return {i, j};
            }
        }
        return {-1, -1};
    }
};