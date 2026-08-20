// Last updated: 8/20/2026, 9:05:20 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int cnt=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]) {
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }

        }
        return cnt;
    }
};