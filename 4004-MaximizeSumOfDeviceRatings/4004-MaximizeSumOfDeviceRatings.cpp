// Last updated: 6/24/2026, 3:29:14 AM
class Solution {
public:
    long long maxRatings(vector<vector<int>>& u) {
        
        int m = u.size(), n = u[0].size();

        int mini = INT_MAX;

        for(auto &v : u){
            ranges::sort(v);
            if(!v.empty()) mini = min(mini, v[0]);
        }

        priority_queue<int> pq, mins;
        unordered_map<int,int> freq;
        int empty = 0;
        for(auto &v : u){
            for(int i = 0; i < v.size(); i++) {
                pq.push(v[i]);
                freq[v[i]]++;
            }

            if(v.size() > 1) mins.push(v[1]);
            else empty++;
        }

        
        
        long long sum = mini;
        freq[mini]--;

        for(int i = 0; i < m - empty - 1; i++){
            freq[mins.top()]--;
            sum += mins.top(); mins.pop();
        }

    
        while(empty--){
            if(freq[pq.top()]) {
                sum += pq.top();
                freq[pq.top()]--;
            } 
            
            pq.pop();
        }

        return sum;
    }
};