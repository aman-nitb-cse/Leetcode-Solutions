// Last updated: 11/6/2026, 4:58:23 AM
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);
        ranges::sort(tasks);
        long long curr_time = tasks[0][0];
        int i = 0;

        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        while(ans.size() < tasks.size()){
            while(i < tasks.size() && tasks[i][0] <= curr_time) 
                pq.push({-tasks[i][1], -tasks[i++][2]});
                
            if(pq.empty()){
                curr_time = tasks[i][0];
                continue;
            }
            auto temp = pq.top(); pq.pop();
            ans.push_back(-temp.second);
            curr_time -= temp.first;
        }
        return ans;
    }
};