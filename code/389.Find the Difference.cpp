class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        int num = s.length();
        
        for(int i = 0; i < num; i++) {
            hash[t[i] - 'a']++;
            hash[s[i] - 'a']--;
        }
        hash[t[num] - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(hash[i]) 
                return i + 'a';
        
        return NULL;
    }
};
