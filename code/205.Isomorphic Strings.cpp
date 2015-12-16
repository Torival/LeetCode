class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens != lent) return false;
        
        int tb1[128]={0};
        int tb2[128]={0};
        int count = 1;
        
        for(int i=0; i<lens; i++) {
            if(!tb1[s[i]]) {
                tb1[s[i]] = count++;
                
                if(!tb2[t[i]])
                    tb2[t[i]] = count-1;
                else return false;
            } else {
                if(!tb2[t[i]]) return false;
                if(tb2[t[i]] != tb1[s[i]]) return false;
            }
        }
        return true;
    }
};
