class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();

        if((lens != lent)) return false;
        if(!lens && !lent) return true;
        
        int a[128] = {0};
        for(int i=0; i<lens; i++) {
            a[s[i]]++;
        }
        for(int i=0; i<lent; i++) {
            a[t[i]]--;
        }
        for(int i=0;i<128; i++) {
            if(a[i]) return false;
        }
        return true;
    }
};
