// Last updated: 6/25/2026, 11:13:27 PM
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        vector<int> left(s.size());
        vector<int> right(s.size());
        vector<int> star(s.size());

        // for left
        int l = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|') l = i;
            left[i] = l;
        }

        // for right 
        int r = -1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '|') r = i;
            right[i] = r;
        }

        // for star
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*') sum++;
            star[i] = sum;
        }

        // final solution algorithm
        vector<int> ans;
        for(int i = 0; i < q.size(); i++){
            if(left[q[i][1]] > q[i][0] && right[q[i][0]] < q[i][1] && q[i][0] != -1) 
                ans.push_back(star[left[q[i][1]]] - star[right[q[i][0]]]);
            else ans.push_back(0);
        }
        return ans;
    }
};