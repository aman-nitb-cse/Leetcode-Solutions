// Last updated: 6/25/2026, 11:16:54 PM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(arr.size());

        queue<array<int,2>> q;
        q.push({0, 0});
        visited[0] = true;

        while(!q.empty()){
            auto [idx, steps] = q.front(); q.pop();
            if(idx + 1 == arr.size()) return steps;

            for(int i : {idx - 1, idx + 1}){
                if(i >= 0 && i < arr.size() && !visited[i]) {
                    q.push({i, steps + 1});
                    visited[i] = true;
                }
            }
            if(!mp.count(arr[idx])) continue;
            for(int &i : mp[arr[idx]]){
                if(i >= 0 && i < arr.size() && !visited[i]) {
                    q.push({i, steps + 1});
                    visited[i] = true;
                }
            }
            mp.erase(arr[idx]);
        }
        return -1;
    }
};