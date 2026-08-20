// Last updated: 8/20/2026, 9:09:52 PM
class Solution {
public:
    string help(int n){
        string d2s[20] = {
            "", 
            "One ", "Two ", "Three ", "Four ", "Five ",
            "Six ", "Seven ", "Eight ", "Nine ",
            "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
            "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "
        };
        string t[10] = {
            "", "", 
            "Twenty ", "Thirty ", "Forty ", "Fifty ",
            "Sixty ", "Seventy ", "Eighty ", "Ninety "
        };

        int unit = n % 10;
        int tens = (n / 10) % 10;
        int hand = (n / 100) % 10;

        string s = "";
        if(hand) s += d2s[hand] + "Hundred ";
        if(tens < 2) s += d2s[n % 100];
        else s += t[tens] + d2s[unit];

        return s;
    }
    string numberToWords(int n) {
        if(n == 0) return "Zero";
        int u = (n % 1000);
        int t = (n / 1000) % 1000;
        int m = (n / 1000000) % 1000;
        int b = (n / 1000000000);

        string s = "";
        if(b) s += help(b) + "Billion ";
        if(m) s += help(m) + "Million ";
        if(t) s += help(t) + "Thousand ";
        if(u) s += help(u);
        s.pop_back();
        return s;
    }
};