// Last updated: 8/20/2026, 9:19:55 PM
class Solution {
public:
    int value(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
	
        int num = 0;
        int n = s.size();
        for(int i = 0; i < n - 1; i++){
            if(value(s[i]) >= value(s[i+1])){
                num += value(s[i]);
            }
            else num -= value(s[i]);
        } 
        return num + value(s[n-1]);
    }
};