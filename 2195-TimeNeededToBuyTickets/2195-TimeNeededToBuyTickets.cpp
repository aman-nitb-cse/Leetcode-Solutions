// Last updated: 6/25/2026, 11:13:18 PM
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        while(tickets[k]){
            for(int i = 0; i < tickets.size(); i++){
                if(tickets[i]){ 
                    tickets[i]--;
                    count++;
                }
                if(tickets[i] == 0 and i == k) return count;
            }
        }
        return count;
    }
};