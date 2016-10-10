class Solution {
public:
    string addStrings(string num1, string num2) {
        int flag = 0;
        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        string val = "";
        
        for(; len1 >=0 && len2 >= 0; len1--, len2--){
            if(num1[len1] + num2[len2] + flag - '0' > '9') {
                val += num1[len1] + num2[len2] + flag - '0' - 10;
                flag = 1;
            } else {
                val += num1[len1] + num2[len2] + flag - '0';
                flag = 0;
            }
        }
        
        if((len1 == -1) && (len2 == -1) && flag > 0) val += "1";
        if(len1 >= 0) add(val, num1, len1, flag);
        if(len2 >= 0) add(val, num2, len2, flag);
        
        reverse(val.begin(), val.end());
        return val;
    }
    
    void add(string &val, string s, int len, int flag) {
        for(; len >= 0; len--) {
            if(s[len] + flag > '9') {
                val += s[len] + flag - 10;
                flag = 1;
            } else {
                val += s[len] + flag;
                flag = 0;
            }
        }
        
        if(flag > 0) val += "1";
    }
};
