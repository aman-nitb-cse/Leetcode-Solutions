// Last updated: 8/20/2026, 8:58:53 PM
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& dest, int source, int target) {
        int n = dest.size(); 
        int m = 1e6; // total stops possible
        
        queue<array<int,2>> q; // {stop, steps}
        vector<vector<int>> bus(m); // stop -> bus
        vector<bool> visBus(n), visStop(m); // avoid reusing same bus and stops

        // initialize bus array

        for(int i = 0; i < n; i++){
            for(int j = 0; j < dest[i].size(); j++){
                bus[dest[i][j]].push_back(i);
            }
        }

        // BFS algorithm

        q.push({source, 0});
        visStop[source] = true;

        while(!q.empty()){
            auto [stop, steps] = q.front(); q.pop();

            if(stop == target) return steps;

            // sit in every unvisited bus
            for(int &i : bus[stop]){
                if(visBus[i]) continue;
                visBus[i] = true;

                // go to every unvisited stop
                for(int &d : dest[i]){
                    if(visStop[d]) continue;
                    visStop[d] = true;
                    q.push({d, steps + 1});
                }
            }
        }

        return -1;
    }
};