// Last updated: 6/25/2026, 11:15:18 PM
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;

        int canDel = nums.size() - k;

        for(int &i : nums){
            
            while(!ans.empty() && canDel && ans.back() > i){
                ans.pop_back();
                canDel--;
            }
            
            ans.push_back(i);
        }
        
        ans.resize(k);

        return ans;
    }
};