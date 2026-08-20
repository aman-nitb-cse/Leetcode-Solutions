// Last updated: 8/20/2026, 9:19:58 PM
class Solution {
public:
    string intToRoman(int n) {
        string s = "";

        if(n >= 1000) s += string(n / 1000, 'M');
        n %= 1000;


        if(n >= 900) s += "CM";
        else if(n >= 500) s += 'D' + string(n / 100 - 5, 'C'); 
        else if(n >= 400) s += "CD";
        else s += string(n / 100, 'C');
        n %= 100;

        if(n >= 90) s += "XC";
        else if(n >= 50) s += 'L' + string(n / 10 - 5, 'X'); 
        else if(n >= 40) s += "XL";
        else s += string(n / 10, 'X'); 
        n %= 10;

        if(n >= 9) s += "IX";
        else if(n >= 5) s += 'V' + string(n - 5, 'I'); 
        else if(n >= 4) s += "IV";
        else s += string(n, 'I'); 

        return s;
    }
};