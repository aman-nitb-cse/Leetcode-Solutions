// Last updated: 11/6/2026, 4:32:29 AM
class Solution {
public:
    int getLength(vector<int>& nums) {

        int n = nums.size(), ans = 1;

        for(int i = 0; i < n; i++){
            unordered_map<int,int> freq, F;
            for(int j = i; j < n; j++){

                if(freq[nums[j]]) {
                    F[freq[nums[j]]]--;
                    if(F[freq[nums[j]]] == 0) F.erase(freq[nums[j]]);
                }
                
                F[++freq[nums[j]]]++;

                if(freq.size() == 1) ans = max(ans , j - i + 1);
                else if(F.size() == 2){
                    int x = F.begin()->first;
                    int y = next(F.begin())->first;

                    if(max(x, y) == 2 * min(x, y)) ans = max(ans , j - i + 1);
                }
            }
        }


        return ans;
    }
};