// Last updated: 6/25/2026, 11:11:47 PM
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> last_day;

        long long breaks = 0;
        long long curr_day = 1;

        for(int &i : tasks){
            long long break_days = 0;

            if(last_day.count(i) && 
               curr_day - last_day[i] <= space){
                
                break_days = 1LL + space + last_day[i] - curr_day;
                breaks += break_days; 
            }

            curr_day += break_days;
            last_day[i] = curr_day;
            curr_day++;
        }

        return breaks + tasks.size();
    }
};