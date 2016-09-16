class Solution {
public:
    string intToRoman(int num) {
        char* str[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        
        string val = "";
        val += str[3][num / 1000 % 10];
        val += str[2][num / 100  % 10];
        val += str[1][num / 10   % 10];
        val += str[0][num        % 10];
        
        return val;
    }
};
