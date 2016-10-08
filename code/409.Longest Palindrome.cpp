class Solution {
public:
    int longestPalindrome(string s) {
        int str[60] = {0};
        int len = s.length();
        int count = 0;
        int flag = 0;
        
        for(int i = 0; i < len; i++)
            str[s[i]-'A']++;
        
        for(int i = 0; i <  60; i++){
            if(str[i] % 2 == 0)
                count += str[i];
            else 
                count += str[i] - 1, flag = 1;
        }
        
        if(flag) count++;
        return count;
    }
};
