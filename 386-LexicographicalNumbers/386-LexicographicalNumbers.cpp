// Last updated: 8/20/2026, 9:07:11 PM
class Solution {
public:

    vector<int> ans;

    void dfs(int n, int curr){

        if(curr > n) return;

        ans.push_back(curr);

        for(int i = 0; i <= 9; i++){

            dfs(n, curr * 10 + i);
            
        }
    }

    vector<int> lexicalOrder(int n) {

        for(int i = 1; i <= 9; i++)
            dfs(n, i);

        return ans;
    }
};