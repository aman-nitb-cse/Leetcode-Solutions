// Last updated: 8/20/2026, 9:02:19 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        vector<int> freq(26);
        for(char &c : tasks) freq[c - 'A']++;
        
        sort(freq.begin(), freq.end());
        
        int maxFreq = freq[25];
        int countMax = 1;
        
        for(int i = 24; i >= 0; i--){
            if(freq[i] == maxFreq) countMax++;
            else break;
        }
        
        int part = (maxFreq - 1) * (n + 1) + countMax;
        
        return max(size, part);
    }
};