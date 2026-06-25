// Last updated: 6/25/2026, 11:13:25 PM
class Solution {
public:
    vector<pair<int,int>> sz;
    vector<pair<int,int>> child;
    long long score = 0;
    int count = 0, n;
    void dfs(int root){
        if(root == -1) return;

        auto &[l, r] = child[root];
        auto &[left, right] = sz[root];
        dfs(l);
        dfs(r);

        if(l != -1) left = sz[l].first + sz[l].second + 1;
        if(r != -1) right = sz[r].first + sz[r].second + 1;
    }
    void f(int root){
        if(root == -1) return;

        auto &[l, r] = child[root];

        f(l);
        f(r);

        auto &[left, right] = sz[root];

        long long sc = 1;
        if(left) sc *= left;
        if(right) sc *= right;
        if(n - 1 - left - right > 0) sc *= n - 1 - left - right;

        if(sc > score){
            score = sc;
            count = 1;
        }
        else if(sc == score) count++;
    }
    int countHighestScoreNodes(vector<int>& p) {
        n = p.size();

        child.assign(n, {-1, -1});
        sz.resize(n);
        for(int i = 1; i < n; i++){
            if(child[p[i]].first == -1) child[p[i]].first = i;
            else child[p[i]].second = i;
        }
        dfs(0);
        f(0);

        return count;
    }
};