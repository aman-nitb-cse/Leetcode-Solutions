// Last updated: 11/6/2026, 5:00:09 AM
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