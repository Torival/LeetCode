class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int str[26] = {0};
        
        for(int i = 0; i < magazine.length(); i++)
            str[magazine[i] - 'a']++;
            
        for(int i = 0; i < ransomNote.length(); i++)
            if(--str[ransomNote[i] - 'a'] < 0) return false;
            
        return true;
    }
};
