class Solution {
public:
    int firstUniqChar(string s) {
        int str[26] = {0};
        int count = 1;
        int first;
        
        for(int i = 0; i < s.length(); i++) {
            if(str[s[i] - 'a'] == 2) 
                continue;
            
            if((str[s[i] - 'a']) & 0x01)
                str[s[i] - 'a'] = 2;
            
            if(str[s[i] - 'a'] == 0) {
                str[s[i] - 'a'] = count;
                count += 2;
            }
        }
        for(int i = 0; i < 26; i++) {
            if((str[i] & 0x01) && (count > str[i])) {
                count = str[i];
                first = i;
            }
        }
        
        for(int i = 0; i < s.length(); i++)
            if(s[i] == first + 'a') return i;
            
        return -1;
    }
};
