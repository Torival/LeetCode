class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        if(!len) return s;
        
        int i = 0;
        int j = len - 1;
        int flag = 2;
        
        while(i != j) {
            if(flag != 1 ) {        //tolower() 大->小      //toupper()小->大
                if((tolower(s[i]) == 'a' || tolower(s[i]) == 'o' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' || tolower(s[i]) == 'u')){
                   if(flag == 2) flag = 1;
                   else flag = 0;
                } else 
                    if(i < j) i++;
            }
            
            if(flag != -1 ){
                if((tolower(s[j]) == 'a' || tolower(s[j]) == 'o' || tolower(s[j]) == 'e' ||
                tolower(s[j]) == 'i' || tolower(s[j]) == 'u')){
                    if(flag == 2) flag = -1;
                   else flag = 0;
                } else 
                    if(i < j) j--;
            }
            
            if(!flag) {
                swap(s[i], s[j]);
                if(i < j) i++;
                if(i < j) j--;
                flag = 2;
            }
        }
        
        return s;
    }
};